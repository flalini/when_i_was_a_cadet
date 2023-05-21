/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:52:46 by ijang             #+#    #+#             */
/*   Updated: 2021/03/07 16:19:20 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static uint64_t	ft_atollu(char *str)
{
	uint64_t	i;

	i = 0;
	while (*str)
		i = i * 10 + *(str++) - '0';
	return (i);
}

static void		init_others(t_philosopher *philos, t_mutexes *mutexes,
		t_condition *con)
{
	unsigned int	i;

	i = -1;
	while (++i < con->philo_num)
	{
		philos[i].start = 1;
		philos[i].num = i + 1;
		philos[i].last_eat = 0;
		philos[i].alive = 1;
		philos[i].eat_count = 0;
		philos[i].first_fork =
			&(mutexes->fork_m[i]);
		philos[i].last_fork =
			&(mutexes->fork_m[(i + 1) % con->philo_num]);
		philos[i].con = con;
		con->monitor_eat[i] = &(philos[i].eat_count);
		pthread_mutex_init(&(mutexes->fork_m[i]), NULL);
		pthread_mutex_init(&(philos[i].eat_m), NULL);
	}
	con->write_m = &(mutexes->write_m);
	pthread_mutex_init(&(mutexes->write_m), NULL);
}

int				alloc_all(t_philosopher **philos, t_mutexes *mutexes,
					t_condition *con)
{
	if (!fl_malloc((void *)philos, sizeof(t_philosopher), con->philo_num))
		return (5);
	if (!fl_malloc((void *)(&(mutexes->fork_m)),
		sizeof(pthread_mutex_t), con->philo_num))
	{
		free(*philos);
		return (5);
	}
	if (!fl_malloc((void *)(&(con->monitor_eat)),
		sizeof(unsigned int *), con->philo_num))
	{
		free(*philos);
		free(mutexes->fork_m);
		return (5);
	}
	if (!fl_malloc((void *)(&(con->monitor_ph)),
		sizeof(pthread_t), con->philo_num))
	{
		free(*philos);
		free(mutexes->fork_m);
		free(con->monitor_eat);
		return (5);
	}
	init_others(*philos, mutexes, con);
	return (0);
}

int				init_condition(t_condition *con, int argc, char **argv)
{
	con->philo_num = (unsigned int)ft_atollu(argv[1]);
	con->to_die = ft_atollu(argv[2]);
	con->to_eat = ft_atollu(argv[3]);
	con->to_sleep = ft_atollu(argv[4]);
	if (argc == 6)
		con->must_eat = (unsigned int)ft_atollu(argv[5]);
	else
		con->must_eat = 0;
	if (con->philo_num < 2)
		return (3);
	if (con->philo_num > 200)
		return (4);
	con->end_process = 0;
	return (0);
}
