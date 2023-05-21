/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 18:26:13 by ijang             #+#    #+#             */
/*   Updated: 2021/03/09 18:47:29 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

char	*make_sem_name(char *name, int num)
{
	if (!num)
		return (ft_strcpy(name, ""SEMNAMEE"000"));
	name[9] = num / 100 + '0';
	name[10] = (num / 10) % 10 + '0';
	name[11] = num % 10 + '0';
	return (name);
}

int		ft_sem_open(sem_t **sem, char *name, int value)
{
	sem_unlink(name);
	*sem = sem_open(name, O_CREAT | O_EXCL, 0644, value);
	if (*sem == SEM_FAILED)
		return (-1);
	return (0);
}
