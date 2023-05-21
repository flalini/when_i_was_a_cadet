/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceil_floor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 22:57:54 by ijang             #+#    #+#             */
/*   Updated: 2020/11/15 22:01:58 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void
	init_draw_ceil_floor(t_calray *ray)
{
	if (ray->side == 0 && ray->ray_dir.x > 0.0)
		set_vect(&ray->floor_wall,
			ray->map_pos.x, ray->map_pos.y + ray->wall_x);
	else if (ray->side == 0 && ray->ray_dir.x < 0.0)
		set_vect(&ray->floor_wall,
			ray->map_pos.x + 1.0, ray->map_pos.y + ray->wall_x);
	else if (ray->side && ray->ray_dir.y > 0.0)
		set_vect(&ray->floor_wall,
			ray->map_pos.x + ray->wall_x, ray->map_pos.y);
	else if (ray->side && ray->ray_dir.y < 0.0)
		set_vect(&ray->floor_wall,
			ray->map_pos.x + ray->wall_x, ray->map_pos.y + 1.0);
}

static void
	draw_ceil_pixel(t_cub3d *cub3d, t_calray *ray, t_vect *pixel, t_vect *p_tex)
{
	t_tex	*t;

	t = &cub3d->tex[TEX_CEIL];
	if (!t->tex)
	{
		draw_pixel(&cub3d->window, pixel,
			distance_shade(cub3d->option, cub3d->color[TEX_CEIL],
			cub3d->sf_dist[ray->loca.y]));
	}
	else
	{
		set_vect(p_tex, (int)(ray->c_floor.x * (double)t->size.x) % t->size.x,
					(int)(ray->c_floor.y * (double)t->size.y) % t->size.y);
		draw_pixel(&cub3d->window, pixel,
			distance_shade(cub3d->option, get_color(t, p_tex),
			cub3d->sf_dist[ray->loca.y]));
	}
}

static void
	draw_floor_pixel(t_cub3d *cub, t_calray *ray, t_vect *pixel, t_vect *p_tex)
{
	t_tex	*t;

	t = &cub->tex[TEX_FLOOR];
	if (!t->tex)
	{
		draw_pixel(&cub->window, pixel,
			distance_shade(cub->option, cub->color[TEX_FLOOR],
			cub->sf_dist[ray->loca.y]));
	}
	else
	{
		set_vect(p_tex, (int)(ray->c_floor.x * (double)t->size.x) % t->size.x,
					(int)(ray->c_floor.y * (double)t->size.y) % t->size.y);
		draw_pixel(&cub->window, pixel,
			distance_shade(cub->option, get_color(t, p_tex),
			cub->sf_dist[ray->loca.y]));
	}
}

void
	draw_ceil_floor(t_cub3d *cub3d, t_calray *ray)
{
	int		i;
	t_vect	pixel;
	double	weight;
	t_vect	p_tex;

	init_draw_ceil_floor(ray);
	pixel.x = ray->loca.x;
	i = cub3d->window.half.y + (ray->height / 2.0);
	while (i < cub3d->window.size.y)
	{
		ray->loca.y = (int)i;
		weight = cub3d->sf_dist[i] / ray->distance;
		set_vect(&ray->c_floor,
			weight * ray->floor_wall.x + (1.0 - weight) * cub3d->camera.pos.x,
			weight * ray->floor_wall.y + (1.0 - weight) * cub3d->camera.pos.y);
		pixel.y = i;
		draw_floor_pixel(cub3d, ray, &pixel, &p_tex);
		pixel.y = cub3d->window.size.y - i++;
		draw_ceil_pixel(cub3d, ray, &pixel, &p_tex);
	}
}
