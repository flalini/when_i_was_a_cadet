/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 20:42:38 by ijang             #+#    #+#             */
/*   Updated: 2021/03/11 21:47:54 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

char	*ft_strcpy(char *dst, char *src)
{
	int		i;

	i = -1;
	while (src[++i])
		dst[i] = src[i];
	dst[i] = 0;
	return (dst);
}

void	clear_all(t_philosopher *p, t_condition *c, t_sems *s)
{
	char		name[225];
	long int	i;

	i = -1;
	while (++i < c->philo_num)
		ft_sem_del(s->eat_s[i], make_sem_name(name, SEMNAMEE, i));
	ft_sem_del(s->write_s, SEMNAMEW);
	ft_sem_del(s->fork_s, SEMNAMEF);
	ft_sem_del(s->monitor_s, SEMNAMEM);
	ft_sem_del(s->finish_s, SEMNAMEER);
	ft_sem_del(s->end_s, SEMNAMED);
	free(p);
	free(s->eat_s);
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

int		free_err(void *to_free)
{
	free(to_free);
	return (-1);
}
