/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 18:26:13 by ijang             #+#    #+#             */
/*   Updated: 2021/03/15 18:22:06 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

char		*make_sem_name(char *name, char *prename, int num)
{
	size_t	i;

	ft_strcpy(name, prename);
	i = ft_strlen(name);
	name[i++] = num / 100 + '0';
	name[i++] = (num / 10) % 10 + '0';
	name[i++] = num % 10 + '0';
	name[i] = 0;
	return (name);
}

int			ft_sem_open(sem_t **sem, char *name, int value, unsigned int m)
{
	sem_unlink(name);
	if (m)
		++value;
	*sem = sem_open(name, O_CREAT | O_EXCL, 0644, value);
	if (*sem == SEM_FAILED)
		return (-1);
	return (0);
}

static int	sem_open_sub(t_sems *sems, unsigned int num, unsigned int i)
{
	char			name[255];

	if (ft_sem_open(&(sems->monitor_s), SEMNAMEM, num, 0))
	{
		sem_unlink(SEMNAMEER);
		sem_unlink(SEMNAMED);
		sem_unlink(SEMNAMEW);
		sem_unlink(SEMNAMEF);
		return (free_err(sems->eat_s));
	}
	while (++i < num)
		if (ft_sem_open(&(sems->eat_s[i]),
			make_sem_name(name, SEMNAMEE, i), 1, 0))
		{
			while (--i >= 0)
				sem_unlink(make_sem_name(name, SEMNAMEE, i));
			sem_unlink(SEMNAMEM);
			sem_unlink(SEMNAMEER);
			sem_unlink(SEMNAMED);
			sem_unlink(SEMNAMEW);
			sem_unlink(SEMNAMEF);
			return (free_err(sems->eat_s));
		}
	return (0);
}

int			sem_open_all(t_condition *con, t_sems *sems)
{
	if (ft_sem_open(&(sems->fork_s), SEMNAMEF, con->philo_num, 0))
		return (free_err(sems->eat_s));
	if (ft_sem_open(&(sems->write_s), SEMNAMEW, 1, 0))
	{
		sem_unlink(SEMNAMEF);
		return (free_err(sems->eat_s));
	}
	if (ft_sem_open(&(sems->end_s), SEMNAMED, con->philo_num, con->must_eat))
	{
		sem_unlink(SEMNAMEW);
		sem_unlink(SEMNAMEF);
		return (free_err(sems->eat_s));
	}
	if (ft_sem_open(&(sems->finish_s), SEMNAMEER, 1, 0))
	{
		sem_unlink(SEMNAMED);
		sem_unlink(SEMNAMEW);
		sem_unlink(SEMNAMEF);
		return (free_err(sems->eat_s));
	}
	return (sem_open_sub(sems, con->philo_num, -1));
}

void		ft_sem_del(sem_t *sem, char *name)
{
	sem_close(sem);
	sem_unlink(name);
}
