/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 19:16:31 by ijang             #+#    #+#             */
/*   Updated: 2020/11/17 19:04:34 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			pars_time(t_pars *pars)
{
	int		i;
	char	**tab;
	int		error_code;

	error_code = 0;
	i = 0;
	while (pars->line[++i])
		if (pars->line[i] != ' ' && pars->line[i] < '0' && pars->line[i] > '9')
			error_code = 4;
	if (!error_code && (tab = ft_split(pars->line, ' ')))
	{
		i = 0;
		while (tab[i])
			++i;
		if (i != 2)
			error_code = 4;
		else
			pars->time = ft_atoi(tab[1]);
		clear_split(tab, -1);
	}
	else if (!error_code)
		error_code = 5;
	free(pars->line);
	return (error_code);
}
