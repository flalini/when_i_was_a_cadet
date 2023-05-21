/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:22:22 by ijang             #+#    #+#             */
/*   Updated: 2021/03/09 19:10:46 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static void	sub_routine(t_philosopher *philo)
{
	pthread_mutex_lock(philo->first_fork);
	if (philo->alive)
		put_message(philo->con, philo->num, TYPEF);
	pthread_mutex_lock(philo->last_fork);
	pthread_mutex_lock(&(philo->eat_m));
	philo->lock = 1;
	if (philo->alive)
	{
		philo->last_eat = get_time();
		put_message(philo->con, philo->num, TYPEE);
		++(philo->eat_count);
		pthread_mutex_unlock(&(philo->eat_m));
		philo->lock = 0;
		ft_usleep(philo->con->to_eat);
	}
	pthread_mutex_unlock(philo->first_fork);
	pthread_mutex_unlock(philo->last_fork);
	if (philo->alive)
		put_message(philo->con, philo->num, TYPES);
	if (philo->alive)
		ft_usleep(philo->con->to_sleep);
	if (philo->alive)
		put_message(philo->con, philo->num, TYPET);
}

void		routine(t_philosopher *philo)
{
	philo->lock = 0;
	philo->last_eat = get_time();
	philo->start = 0;
	while (philo->alive)
		sub_routine(philo);
	if (philo->lock)
		pthread_mutex_unlock(&(philo->eat_m));
}
