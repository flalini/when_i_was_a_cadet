/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:22:22 by ijang             #+#    #+#             */
/*   Updated: 2021/03/09 19:13:32 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static void	sub_routine(t_philosopher *philo)
{
	sem_wait(philo->fork_s);
	if (philo->alive)
		put_message(philo->con, philo->num, TYPEF);
	sem_wait(philo->fork_s);
	sem_wait(philo->eat_s);
	philo->lock = 1;
	if (philo->alive)
	{
		philo->last_eat = get_time();
		put_message(philo->con, philo->num, TYPEE);
		++(philo->eat_count);
		sem_post(philo->eat_s);
		philo->lock = 0;
		ft_usleep(philo->con->to_eat);
	}
	sem_post(philo->fork_s);
	sem_post(philo->fork_s);
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
		sem_post(philo->eat_s);
}
