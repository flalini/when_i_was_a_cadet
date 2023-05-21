/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 18:15:31 by ijang             #+#    #+#             */
/*   Updated: 2020/11/16 22:26:42 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void
	update_window(t_cub3d *cub3d)
{
	t_window	*w;

	w = &cub3d->window;
	mlx_put_image_to_window(w->mlx, w->win, w->screen.ptr, 0, 0);
}

void
	update_screen(t_cub3d *cub3d)
{
	t_window	*w;
	int			i;
	t_calray	ray;
	t_vect		start;

	w = &cub3d->window;
	set_vect(&start, 0, 0);
	i = -1;
	while (++i < w->size.x)
	{
		ray_cast(cub3d, &ray, i);
		cub3d->depth[i] = ray.distance;
		ray.height = fabs((double)(w->size.y) / ray.distance);
		draw_wall(cub3d, &ray);
		if (ray.height < cub3d->window.size.y)
			draw_ceil_floor(cub3d, &ray);
	}
	if (cub3d->sprite)
		draw_sprites(cub3d);
	if (cub3d->space && cub3d->ani[ANI_6].tex)
		draw_motion(cub3d);
	if (cub3d->option & FLAG_UI)
		update_ui(cub3d);
	update_window(cub3d);
}
