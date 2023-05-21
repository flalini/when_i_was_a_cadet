/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 14:01:30 by ijang             #+#    #+#             */
/*   Updated: 2021/03/17 15:38:22 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static long int	creat_philo(t_philosopher *philos, t_condition *con,
		unsigned int i)
{
	if (con->must_eat &&
		pthread_create(&(con->monitor_e_ph), NULL, (void *)monitor_eat, con))
		return (i);
	if (con->must_eat)
		pthread_detach(con->monitor_e_ph);
	while (++i < con->philo_num)
	{
		if (i == (con->philo_num / 2))
			usleep(100);
		if (pthread_create(&(philos[i].routine_ph), NULL,
			(void *)routine, &(philos[i])))
		{
			con->end_process = 1;
			return (i);
		}
		pthread_detach(philos[i].routine_ph);
		if (pthread_create(&(con->monitor_ph[i]), NULL,
			(void *)monitor, &(philos[i])))
		{
			con->end_process = 1;
			return (i);
		}
	}
	return (i);
}

int				start_philo(t_philosopher *philos, t_condition *con)
{
	long int	i;

	con->start_time = get_time();
	i = creat_philo(philos, con, -1);
	if (i != con->philo_num)
	{
		while (--i >= 0)
			pthread_join(con->monitor_ph[i], NULL);
		return (6);
	}
	while (--i >= 0)
		pthread_join(con->monitor_ph[i], NULL);
	return (0);
}
