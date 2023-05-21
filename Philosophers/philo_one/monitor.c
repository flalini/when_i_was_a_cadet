/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 20:50:46 by ijang             #+#    #+#             */
/*   Updated: 2021/03/07 16:19:52 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	monitor_eat(t_condition *con)
{
	unsigned int	i;
	unsigned int	total;

	while (!(con->end_process))
	{
		total = 0;
		i = -1;
		while (++i < con->philo_num)
			if (*(con->monitor_eat[i]) >= con->must_eat)
				++total;
		if (total == con->philo_num)
		{
			con->end_process = 1;
			return ;
		}
	}
}

void	monitor(t_philosopher *philo)
{
	while (philo->start)
	{
	}
	while (!(philo->con->end_process))
	{
		pthread_mutex_lock(&(philo->eat_m));
		if (get_time() - philo->last_eat > philo->con->to_die)
		{
			philo->alive = 0;
			put_dead(philo->con, philo->num);
			pthread_mutex_unlock(&(philo->eat_m));
			return ;
		}
		pthread_mutex_unlock(&(philo->eat_m));
		ft_usleep(2);
	}
	philo->alive = 0;
}
