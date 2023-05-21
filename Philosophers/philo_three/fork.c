/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:48:50 by ijang             #+#    #+#             */
/*   Updated: 2021/03/15 18:43:53 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static int	start_philo_sub(t_philosopher *philos, t_condition *con,
				long int i)
{
	if (con->must_eat)
	{
		con->monitor_e_pid = fork();
		if (con->monitor_e_pid == -1)
		{
			while (--i >= 0)
				kill(philos[i].routine_pid, SIGKILL);
			return (-1);
		}
		else if (con->monitor_e_pid == 0)
		{
			monitor_eat(con);
			exit(EXIT_SUCCESS);
		}
	}
	ft_usleep(10);
	sem_post(con->finish_s);
	sem_wait(con->end_s);
	while (--i >= 0)
		kill(philos[i].routine_pid, SIGKILL);
	if (con->must_eat)
		kill(con->monitor_e_pid, SIGKILL);
	return (0);
}

int			start_philo(t_philosopher *philos, t_condition *con)
{
	long int	i;

	sem_wait(con->finish_s);
	con->start_time = get_time();
	i = -1;
	while (++i < con->philo_num)
	{
		philos[i].routine_pid = fork();
		if (philos[i].routine_pid == -1)
		{
			while (--i >= 0)
				kill(philos[i].routine_pid, SIGKILL);
			return (-1);
		}
		else if (philos[i].routine_pid == 0)
		{
			routine(&(philos[i]));
			exit(EXIT_SUCCESS);
		}
	}
	return (start_philo_sub(philos, con, i));
}
