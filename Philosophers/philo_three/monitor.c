/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 20:50:46 by ijang             #+#    #+#             */
/*   Updated: 2021/03/15 18:31:18 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	monitor_eat(t_condition *con)
{
	unsigned int	i;

	sem_wait(con->end_s);
	sem_wait(con->finish_s);
	sem_post(con->finish_s);
	i = -1;
	while (++i < con->philo_num)
		sem_wait(con->monitor_s);
	sem_wait(con->finish_s);
	sem_post(con->end_s);
	return ;
}

void	monitor(t_philosopher *philo)
{
	while (philo->start)
	{
	}
	while (1)
	{
		sem_wait(philo->con->finish_s);
		sem_post(philo->con->finish_s);
		sem_wait(philo->eat_s);
		if (get_time() - philo->last_eat > philo->con->to_die)
		{
			philo->alive = 0;
			put_dead(philo->con, philo->num);
			sem_post(philo->eat_s);
			break ;
		}
		sem_post(philo->eat_s);
		ft_usleep(2);
	}
}
