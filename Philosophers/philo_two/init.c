/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:52:46 by ijang             #+#    #+#             */
/*   Updated: 2021/03/09 19:39:34 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static uint64_t	ft_atollu(char *str)
{
	uint64_t	i;

	i = 0;
	while (*str)
		i = i * 10 + *(str++) - '0';
	return (i);
}

static void		init_others(t_philosopher *philos, t_sems *sems,
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
		philos[i].fork_s = sems->fork_s;
		philos[i].con = con;
		philos[i].eat_s = sems->eat_s[i];
		con->monitor_eat[i] = &(philos[i].eat_count);
	}
	con->write_s = sems->write_s;
}

static int		sem_open_all(t_condition *con, t_sems *sems)
{
	unsigned int	i;
	char			name[12];

	if (!fl_malloc((void *)(&(sems->eat_s)), sizeof(t_sems *), con->philo_num))
		return (-1);
	if (ft_sem_open(&(sems->fork_s), SEMNAMEF, con->philo_num))
		return (free_err(sems->eat_s));
	if (ft_sem_open(&(sems->write_s), SEMNAMEW, 1))
	{
		sem_unlink(SEMNAMEF);
		return (free_err(sems->eat_s));
	}
	i = -1;
	while (++i < con->philo_num)
		if (ft_sem_open(&(sems->eat_s[i]), make_sem_name(name, i), 1))
		{
			while (--i >= 0)
				sem_unlink(make_sem_name(name, i));
			sem_unlink(SEMNAMEW);
			sem_unlink(SEMNAMEF);
			return (free_err(sems->eat_s));
		}
	return (0);
}

int				alloc_all(t_philosopher **philos, t_sems *sems,
					t_condition *con)
{
	if (!fl_malloc((void *)philos, sizeof(t_philosopher), con->philo_num))
		return (ERR6);
	if (!fl_malloc((void *)(&(con->monitor_eat)),
		sizeof(unsigned int *), con->philo_num))
	{
		free(*philos);
		return (ERR6);
	}
	if (!fl_malloc((void *)(&(con->monitor_ph)),
		sizeof(pthread_t), con->philo_num))
	{
		free(*philos);
		free(con->monitor_eat);
		return (ERR6);
	}
	if (sem_open_all(con, sems))
	{
		free(*philos);
		free(con->monitor_eat);
		free(con->monitor_ph);
		return (ERR8);
	}
	init_others(*philos, sems, con);
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
		return (ERR4);
	if (con->philo_num > 200)
		return (ERR5);
	con->end_process = 0;
	return (0);
}
