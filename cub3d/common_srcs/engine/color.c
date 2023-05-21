/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 17:58:07 by ijang             #+#    #+#             */
/*   Updated: 2020/11/14 19:45:00 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		shade_color(int color, double divide)
{
	if (divide <= 1.0)
		return (color);
	return ((((int)((double)(0xFF0000 & color) / divide)) & 0xFF0000)
		+ (((int)((double)(0x00FF00 & color) / divide)) & 0x00FF00)
		+ ((int)((double)(0x0000FF & color) / divide)));
}

int		distance_shade(int options, int color, double distance)
{
	if (options & FLAG_SHADOWS)
		return (shade_color(color, distance / 1.5));
	return (color);
}

int		get_color(t_tex *tex, t_vect *pos)
{
	if (pos->x >= 0 && pos->x < tex->size.x
		&& pos->y >= 0 && pos->y < tex->size.y)
		return (tex->data[(tex->size.x * (int)pos->y) + (int)pos->x]);
	return (0);
}
