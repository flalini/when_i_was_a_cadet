/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 12:27:01 by ijang             #+#    #+#             */
/*   Updated: 2021/03/07 16:20:11 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static int		ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		++i;
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}

static int		ft_isnumerics(int i, char **strs)
{
	int		j;
	int		error;

	error = 0;
	while (--i)
	{
		j = -1;
		while (strs[i][++j])
			if (strs[i][j] < '0' || strs[i][j] > '9')
				error = 1;
		if (!error && (j > 10
			|| (j == 10 && ft_strcmp(strs[i], "4294967295") > 0)))
			error = 2;
	}
	return (error);
}

int				main(int argc, char **argv)
{
	t_condition		con;
	t_philosopher	*philos;
	t_mutexes		mutexes;
	int				error;

	error = 0;
	if (argc < 5 || argc > 6 || err_check(&error, ft_isnumerics(argc, argv))
		|| err_check(&error, init_condition(&con, argc, argv))
		|| err_check(&error, alloc_all(&philos, &mutexes, &con)))
		return (put_error(error));
	error = start_philo(philos, &con);
	ft_usleep(1);
	clear_all(philos, &con, &mutexes);
	if (error)
		return (put_error(6));
	return (0);
}
