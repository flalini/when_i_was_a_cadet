/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 22:22:07 by ijang             #+#    #+#             */
/*   Updated: 2020/11/18 12:47:13 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		move_camera(t_cub3d *cub3d, double direction)
{
	t_camera	*c;
	t_vect		n_pos;

	c = &cub3d->camera;
	copy_vect(&n_pos, &c->pos);
	n_pos.x += direction * (c->dir.x * cub3d->dash * M_SPEED);
	if (in_map(&n_pos, cub3d)
		&& map(&n_pos, cub3d) == '0')
		c->pos.x = n_pos.x;
	n_pos.x = c->pos.x;
	n_pos.y += direction * (c->dir.y * cub3d->dash * M_SPEED);
	if (in_map(&n_pos, cub3d)
		&& map(&n_pos, cub3d) == '0')
		c->pos.y = n_pos.y;
	return (1);
}

int		move_perp_camera(t_cub3d *cub3d, int direction)
{
	t_camera	*c;
	t_vect		n_pos;

	c = &cub3d->camera;
	copy_vect(&n_pos, &c->pos);
	n_pos.x += direction * (c->x_dir.x * cub3d->dash * M_SPEED);
	if (in_map(&n_pos, cub3d)
		&& map(&n_pos, cub3d) == '0')
		c->pos.x = n_pos.x;
	n_pos.x = c->pos.x;
	n_pos.y += direction * (c->x_dir.y * cub3d->dash * M_SPEED);
	if (in_map(&n_pos, cub3d)
		&& map(&n_pos, cub3d) == '0')
		c->pos.y = n_pos.y;
	return (1);
}

int		rotate_camera(t_cub3d *cub3d, int dir)
{
	t_camera	*c;
	double		old;

	c = &cub3d->camera;
	old = c->dir.x;
	c->dir.x = (c->dir.x * cub3d->cos[dir]) - (c->dir.y * cub3d->sin[dir]);
	c->dir.y = (old * cub3d->sin[dir]) + (c->dir.y * cub3d->cos[dir]);
	c->plane.x = -cub3d->fov * c->dir.y;
	c->plane.y = cub3d->fov * c->dir.x;
	c->x_dir.x = c->dir.y;
	c->x_dir.y = -(c->dir.x);
	return (1);
}
