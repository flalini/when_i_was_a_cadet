/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 20:20:11 by ijang             #+#    #+#             */
/*   Updated: 2020/11/18 12:56:21 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	modifing(t_vect *pos, t_vect *next, t_cub3d *cub3d)
{
	cub3d->map[((int)floor(next->y) * cub3d->map_size.x)
		+ (int)floor(next->x)] = map(pos, cub3d);
	cub3d->map[((int)floor(pos->y) * cub3d->map_size.x)
		+ (int)floor(pos->x)] = '0';
	modify_sprite(&cub3d->sprite, pos, next);
}

int			interaction(t_cub3d *cub3d)
{
	t_calray	ray;
	t_vect		next;
	int			next_side;
	int			c;

	copy_vect(&ray.ray_pos, &cub3d->camera.pos);
	init_ray(&ray, &cub3d->camera, 0, 0);
	next_side = (ray.side_dist.x < ray.side_dist.y);
	ray.map_pos.x += ((next_side) ? ray.step.x : 0.0);
	ray.map_pos.y += ((!next_side) ? ray.step.y : 0.0);
	if (in_map(&ray.map_pos, cub3d) && (c = map(&ray.map_pos, cub3d))
		&& (c == '3' || c == '4'))
	{
		copy_vect(&next, &ray.map_pos);
		next.x += ((next_side) ? ray.step.x : 0.0);
		next.y += ((!next_side) ? ray.step.y : 0.0);
		if (map(&next, cub3d) == '0')
			modifing(&ray.map_pos, &next, cub3d);
		else if (c == '4' && (cub3d->map[((int)floor(ray.map_pos.y)
			* cub3d->map_size.x) + (int)floor(ray.map_pos.x)] = '0'))
			delete_sprite(&cub3d->sprite, &ray.map_pos);
	}
	return (1);
}
