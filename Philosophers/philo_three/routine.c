/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:22:22 by ijang             #+#    #+#             */
/*   Updated: 2021/03/15 23:47:01 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static void	sub_routine(t_philosopher *philo)
{
	sem_wait(philo->con->finish_s);
	sem_post(philo->con->finish_s);
	sem_wait(philo->fork_s);
	if (philo->alive)
		put_message(philo->con, philo->num, TYPEF);
	sem_wait(philo->fork_s);
	sem_wait(philo->eat_s);
	if (philo->alive)
	{
		philo->last_eat = get_time();
		put_message(philo->con, philo->num, TYPEE);
		if (++(philo->eat_count) == philo->con->must_eat)
			sem_post(philo->con->monitor_s);
		sem_post(philo->eat_s);
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
	philo->start = 1;
	sem_wait(philo->con->monitor_s);
	sem_wait(philo->con->end_s);
	sem_wait(philo->con->finish_s);
	sem_post(philo->con->finish_s);
	if (pthread_create(&(philo->monitor_ph), NULL,
		(void *)monitor, philo))
	{
		sem_wait(philo->con->finish_s);
		sem_post(philo->con->end_s);
		put_error(ERR7);
		exit(EXIT_FAILURE);
	}
	pthread_detach(philo->monitor_ph);
	philo->last_eat = get_time();
	philo->start = 0;
	if (philo->num % 2)
		ft_usleep(5);
	while (philo->alive)
		sub_routine(philo);
	sem_post(philo->con->end_s);
}
