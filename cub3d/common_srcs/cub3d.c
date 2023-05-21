/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:56:25 by ijang             #+#    #+#             */
/*   Updated: 2020/11/18 13:00:02 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int
	check_clear(t_cub3d *cub3d)
{
	t_vect	pos;

	copy_vect(&pos, &cub3d->camera.pos);
	if (map_xy(pos.x - 1.0, pos.y, cub3d) == '5'
		|| map_xy(pos.x + 1.0, pos.y, cub3d) == '5'
		|| map_xy(pos.x, pos.y - 1.0, cub3d) == '5'
		|| map_xy(pos.x, pos.y + 1.0, cub3d) == '5')
	{
		cub3d->exit = 1;
		cub3d->clear = 1;
	}
	if (cub3d->frame == cub3d->time * FRAME_UNIT)
		cub3d->exit = 1;
	return (0);
}

int
	exit_cub3d(t_cub3d *cub3d)
{
	clear_animations(cub3d);
	clear_sprites(&cub3d->sprite);
	clear_window(&cub3d->window);
	if (cub3d->clear == 1)
		write(1, "YOU WIN!\n", 8);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
