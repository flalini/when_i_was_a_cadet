/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 14:53:49 by ijang             #+#    #+#             */
/*   Updated: 2021/03/07 16:21:40 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

size_t			ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

int				put_error(int i)
{
	if (i == 0)
		write(2, ERRMESSAGE1, ft_strlen(ERRMESSAGE1));
	if (i == 1)
		write(2, ERRMESSAGE2, ft_strlen(ERRMESSAGE2));
	if (i == 2)
		write(2, ""ERRMESSAGE3""ERRMESSAGE4"",
			ft_strlen(""ERRMESSAGE3""ERRMESSAGE4""));
	if (i == 3)
		write(2, ERRMESSAGE5, ft_strlen(ERRMESSAGE5));
	if (i == 4)
		write(2, ERRMESSAGE6, ft_strlen(ERRMESSAGE6));
	if (i == 5)
		write(2, ERRMESSAGE7, ft_strlen(ERRMESSAGE7));
	if (i == 6)
		write(2, ERRMESSAGE8, ft_strlen(ERRMESSAGE8));
	return (i + 1);
}

void			put_dead(t_condition *con, unsigned int num)
{
	pthread_mutex_lock(con->write_m);
	if (!(con->end_process))
	{
		printf("%-*s %-3d"STATEMESSAGED"",
			22 - printf("%llu", get_time() - con->start_time), "ms", num);
		con->end_process = 1;
	}
	pthread_mutex_unlock(con->write_m);
}

void			put_message(t_condition *con, unsigned int num, int type)
{
	pthread_mutex_lock(con->write_m);
	if (!(con->end_process))
	{
		if (type == TYPEF)
			printf("%-*s %-3d"STATEMESSAGEF"",
				22 - printf("%llu", get_time() - con->start_time), "ms", num);
		else if (type == TYPEE)
		{
			printf("%-*s %-3d"STATEMESSAGEF"",
				22 - printf("%llu", get_time() - con->start_time), "ms", num);
			printf("%-*s %-3d"STATEMESSAGEE"",
				22 - printf("%llu", get_time() - con->start_time), "ms", num);
		}
		else if (type == TYPES)
			printf("%-*s %-3d"STATEMESSAGES"",
				22 - printf("%llu", get_time() - con->start_time), "ms", num);
		else
			printf("%-*s %-3d"STATEMESSAGET"",
				22 - printf("%llu", get_time() - con->start_time), "ms", num);
	}
	pthread_mutex_unlock(con->write_m);
}
