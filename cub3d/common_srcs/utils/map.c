/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:30:53 by ijang             #+#    #+#             */
/*   Updated: 2020/11/18 13:17:01 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		in_map(t_vect *pos, t_cub3d *cub3d)
{
	return ((int)floor(pos->x) >= 0 && (int)floor(pos->y) >= 0
	&& (int)floor(pos->x) < cub3d->map_size.x
	&& (int)floor(pos->y) < cub3d->map_size.y);
}

int		map(t_vect *pos, t_cub3d *cub3d)
{
	return (cub3d->map[((int)floor(pos->y) * cub3d->map_size.x)
		+ (int)floor(pos->x)]);
}

int		map_xy(double x, double y, t_cub3d *cub3d)
{
	return (cub3d->map[((int)floor(y) * cub3d->map_size.x)
		+ (int)floor(x)]);
}

int		map_ixy(int x, int y, t_cub3d *cub3d)
{
	return (cub3d->map[(y * cub3d->map_size.x) + x]);
}

double	max(double x, double y)
{
	return ((x > y) ? x : y);
}
