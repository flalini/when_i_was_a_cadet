/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 17:50:15 by ijang             #+#    #+#             */
/*   Updated: 2020/11/16 19:43:04 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	line_is_empty(t_tex *tex, int line)
{
	int		i;
	t_vect	pos;

	pos.y = line;
	i = -1;
	while (++i < tex->size.x)
	{
		pos.x = i;
		if (get_color(tex, &pos) != EMPTY_COLOR)
			return (0);
	}
	return (1);
}

static int	column_is_empty(t_tex *tex, int column)
{
	int		i;
	t_vect	pos;

	pos.x = column;
	i = -1;
	while (++i < tex->size.y)
	{
		pos.y = i;
		if (get_color(tex, &pos) != EMPTY_COLOR)
			return (0);
	}
	return (1);
}

void		find_texture_empty(t_tex *tex)
{
	int	i;

	i = 0;
	while (i < tex->size.x && column_is_empty(tex, i))
		++i;
	tex->start.x = i--;
	while (++i < tex->size.x)
		if (!column_is_empty(tex, i))
			tex->end.x = i;
	i = 0;
	while (i < tex->size.y && line_is_empty(tex, i))
		++i;
	tex->start.y = i--;
	while (++i < tex->size.y)
		if (!line_is_empty(tex, i))
			tex->end.y = i;
}
