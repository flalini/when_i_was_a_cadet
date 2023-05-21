/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 22:56:10 by ijang             #+#    #+#             */
/*   Updated: 2020/11/18 13:09:27 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_draw_wall(t_tex *tex, t_calray *ray, t_vect *p_tex)
{
	if (ray->side)
		ray->wall_x = ray->ray_pos.x
			+ ((ray->map_pos.y - ray->ray_pos.y
				+ (1. - ray->step.y) / 2.) / ray->ray_dir.y)
			* ray->ray_dir.x;
	else
		ray->wall_x = ray->ray_pos.y
			+ ((ray->map_pos.x - ray->ray_pos.x
				+ (1. - ray->step.x) / 2.) / ray->ray_dir.x)
			* ray->ray_dir.y;
	ray->wall_x -= floor(ray->wall_x);
	p_tex->x = (int)(ray->wall_x * (double)tex->size.x);
	if (ray->side == 0 && ray->ray_dir.x > 0.0)
		p_tex->x = (double)tex->size.x - p_tex->x - 1.0;
	else if (ray->side == 1 && ray->ray_dir.y < 0.0)
		p_tex->x = (double)tex->size.x - p_tex->x - 1.0;
}

void		draw_wall(t_cub3d *c, t_calray *r)
{
	int		i[2];
	t_vect	p_tex;
	t_tex	*tex;
	t_vect	pixel;

	tex = &c->tex[r->direction];
	set_vect(&pixel, r->loca.x, max(0, c->window.half.y - (r->height / 2.0)));
	if (!tex->tex)
	{
		draw_vertical_line(&c->window, &pixel, r->height,
			distance_shade(c->option, c->color[r->direction], r->distance));
		return ;
	}
	init_draw_wall(tex, r, &p_tex);
	i[1] = max(0, c->window.half.y - (r->height / 2.0));
	i[0] = 0;
	while (i[0] < r->height && (pixel.y = i[1]++) < c->window.size.y)
	{
		p_tex.y = (int)((pixel.y * 2 - c->window.size.y + r->height)
				* ((tex->size.y / 2.0) / r->height));
		draw_pixel(&c->window, &pixel, distance_shade(c->option,
			get_color(tex, &p_tex), r->distance));
		i[0]++;
	}
}
