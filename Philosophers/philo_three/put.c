/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 14:53:49 by ijang             #+#    #+#             */
/*   Updated: 2021/03/11 21:07:42 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

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
	if (i == ERR1)
		write(2, ERRMESSAGE1, ft_strlen(ERRMESSAGE1));
	else if (i == ERR2)
		write(2, ERRMESSAGE2, ft_strlen(ERRMESSAGE2));
	else if (i == ERR3)
		write(2, ""ERRMESSAGE3""ERRMESSAGE4"",
			ft_strlen(""ERRMESSAGE3""ERRMESSAGE4""));
	else if (i == ERR4)
		write(2, ERRMESSAGE5, ft_strlen(ERRMESSAGE5));
	else if (i == ERR5)
		write(2, ERRMESSAGE6, ft_strlen(ERRMESSAGE6));
	else if (i == ERR6)
		write(2, ERRMESSAGE7, ft_strlen(ERRMESSAGE7));
	else if (i == ERR7)
		write(2, ERRMESSAGE8, ft_strlen(ERRMESSAGE8));
	else if (i == ERR8)
		write(2, ERRMESSAGE9, ft_strlen(ERRMESSAGE9));
	else if (i == ERR9)
		write(2, ERRMESSAGE10, ft_strlen(ERRMESSAGE10));
	return (i + 1);
}

void			put_dead(t_condition *con, unsigned int num)
{
	sem_wait(con->finish_s);
	sem_wait(con->write_s);
	printf("%-*s %-3d"STATEMESSAGED"",
		22 - printf("%llu", get_time() - con->start_time), "ms", num);
	sem_post(con->end_s);
}

void			put_message(t_condition *con, unsigned int num, int type)
{
	sem_wait(con->finish_s);
	sem_post(con->finish_s);
	sem_wait(con->write_s);
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
	sem_post(con->write_s);
}
