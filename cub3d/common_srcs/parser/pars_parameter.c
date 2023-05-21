/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_parameter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:03:21 by ijang             #+#    #+#             */
/*   Updated: 2020/11/16 15:06:29 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			pars_resolution(t_pars *pars)
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
		if (i != 3)
			error_code = 4;
		else
			set_loca(&(pars->r_size), ft_atoi(tab[1]), ft_atoi(tab[2]));
		clear_split(tab, -1);
	}
	else if (!error_code)
		error_code = 5;
	free(pars->line);
	return (error_code);
}

static int	pars_color_set(unsigned int *c, char *s)
{
	int		i;
	int		error_code;
	char	**rgb;

	error_code = 0;
	if (!(rgb = ft_split(s, ',')))
		return (5);
	i = 0;
	while (rgb[i])
		++i;
	if (i != 3 || ft_atoi(rgb[0]) > 255 || ft_atoi(rgb[0]) < 0 ||
			ft_atoi(rgb[1]) > 255 || ft_atoi(rgb[1]) < 0 ||
			ft_atoi(rgb[2]) > 255 || ft_atoi(rgb[2]) < 0)
		error_code = 4;
	else
		*c = (ft_atoi(rgb[0]) << 16)
			+ (ft_atoi(rgb[1]) << 8) + ft_atoi(rgb[2]);
	clear_split(rgb, -1);
	return (error_code);
}

int			pars_color(t_pars *pars, int tex_num)
{
	int		i;
	char	**tab;
	int		error_code;

	error_code = 0;
	i = 0;
	while (pars->line[++i])
		if (pars->line[i] != ' ' && pars->line[i] != ','
				&& pars->line[i] < '0' && pars->line[i] > '9')
			error_code = 4;
	if (!error_code && (tab = ft_split(pars->line, ' ')))
	{
		i = 0;
		while (tab[i])
			++i;
		if (i != 2)
			error_code = 4;
		else
			error_code = pars_color_set(&(pars->color[tex_num]), tab[1]);
		clear_split(tab, -1);
	}
	else if (!error_code)
		error_code = 5;
	free(pars->line);
	return (error_code);
}

int			pars_texture(t_pars *pars, int key)
{
	int		i;
	char	**tab;
	int		error_code;

	error_code = 0;
	if (pars->tex_path[key])
	{
		free(pars->tex_path[key]);
		pars->tex_path[key] = NULL;
	}
	if ((tab = ft_split(pars->line, ' ')))
	{
		i = 0;
		while (tab[i])
			++i;
		if (i != 2)
			error_code = 4;
		else
			pars->tex_path[key] = tab[1];
		clear_split(tab, 1);
	}
	else
		error_code = 5;
	free(pars->line);
	return (error_code);
}

int			pars_ani(t_pars *pars, int key)
{
	char	**tab;
	int		error_code;

	error_code = 0;
	if (pars->ani_path[key])
	{
		clear_split(pars->ani_path[key], -1);
		pars->ani_path[key] = NULL;
	}
	if ((tab = ft_split(pars->line, ' ')))
		pars->ani_path[key] = tab;
	else
		error_code = 5;
	free(pars->line);
	return (error_code);
}
