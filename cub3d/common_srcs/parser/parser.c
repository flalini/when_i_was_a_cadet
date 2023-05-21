/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 18:23:57 by ijang             #+#    #+#             */
/*   Updated: 2020/11/29 20:09:44 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_pars(t_pars *pars)
{
	int		i;

	pars->map_end = 0;
	set_loca(&(pars->r_size), 848, 480);
	pars->time = 4242.0;
	i = -1;
	while (++i < PARS_NUM)
		pars->set[i] = 0;
	i = -1;
	while (++i < TEXTURES_NUM)
		pars->tex_path[i] = NULL;
	i = -1;
	while (++i < ANIMATION_NUM)
		pars->ani_path[i] = NULL;
	pars->color[TEX_NORTH] = 0xFFFFFF;
	pars->color[TEX_SOUTH] = 0xCCCCCC;
	pars->color[TEX_WEST] = 0xFF44FF;
	pars->color[TEX_EAST] = 0x44FF44;
	pars->color[TEX_CEIL] = 0x33C6E3;
	pars->color[TEX_FLOOR] = 0xA0764C;
	pars->buffer = NULL;
}

static void	clear_pars(t_pars *pars)
{
	t_strlst	*tmp;
	int			i;

	close(pars->m_fd);
	while (pars->buffer)
	{
		tmp = (pars->buffer)->next;
		if ((pars->buffer)->text)
			free((pars->buffer)->text);
		free(pars->buffer);
		pars->buffer = tmp;
	}
	i = -1;
	while (++i < TEXTURES_NUM)
		if (pars->tex_path[i])
			free(pars->tex_path[i]);
	i = -1;
	while (++i < ANIMATION_NUM)
		if (pars->ani_path[i])
			clear_split(pars->ani_path[i], -1);
}

static int	parsing_error(t_pars *pars, int error_code)
{
	clear_pars(pars);
	return (error_code);
}

static int	parse_line(t_pars *pars, size_t len, int key)
{
	if (len >= ((size_t)1) << (sizeof(int) * 8))
		return (3);
	if (pars->map_end)
		return (4);
	if (!len)
	{
		free(pars->line);
		if (pars->set[P_MAP])
			pars->map_end = 1;
		return (0);
	}
	if ((key = pars_key(pars->line)) != P_MAP && pars->set[P_MAP])
		return (4);
	if (key == P_R)
		return (pars_resolution(pars));
	else if (key >= P_NO && key <= PARS_TEX)
		return (pars_texture(pars, key - P_NO));
	else if (key == P_C || key == P_F)
		return (pars_color(pars, (key == P_C) ? TEX_CEIL : TEX_FLOOR));
	else if (key >= P_A3 && key <= PARS_ANI)
		return (pars_ani(pars, key - P_A3));
	else if (key == P_T)
		return (pars_time(pars));
	pars->set[key] = 1;
	return (strlst_add_back(&(pars->buffer), pars->line));
}

int			parser(t_cub3d *cub3d, char *map_path)
{
	t_pars	pars;
	int		check_gnl;
	int		error_code;

	if (ft_check_ext(map_path, ".cub"))
		return (1);
	if ((pars.m_fd = open(map_path, O_RDONLY)) < 0)
		return (2);
	init_pars(&pars);
	while ((check_gnl = get_next_line(pars.m_fd, &(pars.line))) == 1)
		if ((error_code = parse_line(&pars, ft_strlen(pars.line), 0)))
			return (parsing_error(&pars, error_code));
	if (check_gnl == -1)
		return (parsing_error(&pars, 8));
	if (ft_strlen(pars.line)
		&& (error_code = strlst_add_back(&(pars.buffer), pars.line)))
		return (parsing_error(&pars, error_code));
	else if (!ft_strlen(pars.line))
		free(pars.line);
	if (!(error_code = map_parsing(cub3d, pars.buffer)))
		error_code = set_cub3d(cub3d, &pars);
	clear_pars(&pars);
	return (error_code);
}
