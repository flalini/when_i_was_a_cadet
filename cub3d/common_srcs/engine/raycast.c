/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 18:24:39 by ijang             #+#    #+#             */
/*   Updated: 2020/11/18 12:57:34 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			wall_direction(t_calray *ray)
{
	if (ray->side)
		return ((ray->ray_dir.y < 0) ? (TEX_NORTH) : (TEX_SOUTH));
	return ((ray->ray_dir.x < 0) ? (TEX_WEST) : (TEX_EAST));
}

void		init_ray(t_calray *r, t_camera *c, int x, double camera_x)
{
	r->loca.x = x;
	set_vect(&r->map_pos, (int)c->pos.x, (int)c->pos.y);
	set_vect(&r->ray_dir, c->dir.x + c->plane.x * camera_x,
			c->dir.y + c->plane.y * camera_x);
	r->delta_dist.x = fabs(1.0 / r->ray_dir.x);
	r->delta_dist.y = fabs(1.0 / r->ray_dir.y);
	if (r->ray_dir.x < 0.0)
	{
		set_vect(&r->step, -1.0, (r->ray_dir.y < 0.0) ? -1.0 : 1.0);
		r->side_dist.x = (r->ray_pos.x - r->map_pos.x) * r->delta_dist.x;
	}
	else
	{
		set_vect(&r->step, 1.0, (r->ray_dir.y < 0.0) ? -1.0 : 1.0);
		r->side_dist.x = (r->map_pos.x + 1.0 - r->ray_pos.x) * r->delta_dist.x;
	}
	if (r->ray_dir.y < 0.0)
		r->side_dist.y = (r->ray_pos.y - r->map_pos.y) * r->delta_dist.y;
	else
		r->side_dist.y = (r->map_pos.y + 1.0 - r->ray_pos.y) * r->delta_dist.y;
}

double		ray_distance(t_cub3d *cub3d, t_calray *r)
{
	double	pos;

	if (r->side)
	{
		pos = (r->map_pos.y - cub3d->camera.pos.y + (1.0 - r->step.y) / 2.0);
		return (fabs(pos / r->ray_dir.y));
	}
	pos = (r->map_pos.x - cub3d->camera.pos.x + (1.0 - r->step.x) / 2.0);
	return (fabs(pos / r->ray_dir.x));
}

void		ray_cast(t_cub3d *cub3d, t_calray *ray, int x)
{
	int		hit;
	int		next_side;

	copy_vect(&ray->ray_pos, &cub3d->camera.pos);
	init_ray(ray, &cub3d->camera, x, cub3d->camera_x[x]);
	hit = 0;
	while (!hit)
	{
		next_side = (ray->side_dist.x < ray->side_dist.y);
		ray->side_dist.x += ((next_side) ? ray->delta_dist.x : 0.0);
		ray->map_pos.x += ((next_side) ? ray->step.x : 0.0);
		ray->side_dist.y += ((!next_side) ? ray->delta_dist.y : 0.0);
		ray->map_pos.y += ((!next_side) ? ray->step.y : 0.0);
		ray->side = !next_side;
		if (!in_map(&ray->map_pos, cub3d))
		{
			ray->map_pos.x -= ((!ray->side) ? ray->step.x : 0.0);
			ray->map_pos.y -= ((ray->side) ? ray->step.y : 0.0);
			hit = 1;
		}
		else if (map(&ray->map_pos, cub3d) == '1')
			hit = 1;
	}
	ray->distance = ray_distance(cub3d, ray);
	ray->direction = wall_direction(ray);
}
