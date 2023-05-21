/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 20:50:46 by ijang             #+#    #+#             */
/*   Updated: 2021/03/09 19:14:55 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

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
		ft_usleep(1);
	}
}

void	monitor(t_philosopher *philo)
{
	while (philo->start)
	{
	}
	while (!(philo->con->end_process))
	{
		sem_wait(philo->eat_s);
		if (get_time() - philo->last_eat > philo->con->to_die)
		{
			philo->alive = 0;
			put_dead(philo->con, philo->num);
			sem_post(philo->eat_s);
			return ;
		}
		sem_post(philo->eat_s);
		ft_usleep(2);
	}
	philo->alive = 0;
}
