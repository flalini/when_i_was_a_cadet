/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 20:42:38 by ijang             #+#    #+#             */
/*   Updated: 2021/03/07 16:02:30 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	clear_all(t_philosopher *p, t_condition *c, t_mutexes *m)
{
	long int	i;

	i = -1;
	while (++i < c->philo_num)
	{
		pthread_mutex_destroy(&(p->eat_m));
		pthread_mutex_destroy(&(m->fork_m[i]));
	}
	pthread_mutex_destroy(&(m->write_m));
	free(p);
	free(c->monitor_eat);
	free(m->fork_m);
	free(c->monitor_ph);
}

int		err_check(int *error, int result)
{
	*error = result;
	return (result);
}

void	*fl_malloc(void **to_malloc, size_t size, size_t len)
{
	*to_malloc = malloc(size * len);
	return (*to_malloc);
}
