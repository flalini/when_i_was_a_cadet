/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 20:42:38 by ijang             #+#    #+#             */
/*   Updated: 2021/03/17 15:58:41 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

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
	char		name[12];
	long int	i;

	i = -1;
	while (++i < c->philo_num)
		sem_unlink(make_sem_name(name, i));
	sem_unlink(SEMNAMEW);
	sem_unlink(SEMNAMEF);
	free(p);
	free(c->monitor_eat);
	free(c->monitor_ph);
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
