/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 14:53:49 by ijang             #+#    #+#             */
/*   Updated: 2021/03/09 19:17:19 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

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
	if (i == ERR2)
		write(2, ERRMESSAGE2, ft_strlen(ERRMESSAGE2));
	if (i == ERR3)
		write(2, ""ERRMESSAGE3""ERRMESSAGE4"",
			ft_strlen(""ERRMESSAGE3""ERRMESSAGE4""));
	if (i == ERR4)
		write(2, ERRMESSAGE5, ft_strlen(ERRMESSAGE5));
	if (i == ERR5)
		write(2, ERRMESSAGE6, ft_strlen(ERRMESSAGE6));
	if (i == ERR6)
		write(2, ERRMESSAGE7, ft_strlen(ERRMESSAGE7));
	if (i == ERR7)
		write(2, ERRMESSAGE8, ft_strlen(ERRMESSAGE8));
	if (i == ERR8)
		write(2, ERRMESSAGE9, ft_strlen(ERRMESSAGE9));
	return (i + 1);
}

void			put_dead(t_condition *con, unsigned int num)
{
	sem_wait(con->write_s);
	if (!(con->end_process))
	{
		printf("%-*s %-3d"STATEMESSAGED"",
			22 - printf("%llu", get_time() - con->start_time), "ms", num);
		con->end_process = 1;
	}
	sem_post(con->write_s);
}

void			put_message(t_condition *con, unsigned int num, int type)
{
	sem_wait(con->write_s);
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
	sem_post(con->write_s);
}
