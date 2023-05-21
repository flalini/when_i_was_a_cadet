/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tables.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:06:49 by ijang             #+#    #+#             */
/*   Updated: 2020/11/14 00:40:20 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calculate_camera_x(double width, double *r)
{
	int	i;

	i = -1;
	while (++i < width)
		r[i] = ((2.0 * (double)i) / width) - 1.0;
}

static void	calculate_cos_sin(double *cos_r, double *sin_r)
{
	cos_r[0] = cos(-R_SPEED);
	cos_r[1] = cos(R_SPEED);
	sin_r[0] = sin(-R_SPEED);
	sin_r[1] = sin(R_SPEED);
}

static void	calculate_sf_dist(double height, double *r)
{
	int	i;

	i = -1;
	while (++i < height)
		r[i] = (height / (2.0 * (double)i - height));
	r[i] = 1.0 / 0.0;
}

void		make_tables(t_cub3d *cub3d)
{
	calculate_camera_x((double)(cub3d->window.size.x), cub3d->camera_x);
	calculate_cos_sin(cub3d->cos, cub3d->sin);
	calculate_sf_dist((double)(cub3d->window.size.y), cub3d->sf_dist);
}
