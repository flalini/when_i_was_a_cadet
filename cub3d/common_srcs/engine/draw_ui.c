/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ui.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:58:17 by ijang             #+#    #+#             */
/*   Updated: 2020/11/18 12:58:57 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int
	case_color(t_cub3d *cub3d, int x, int y)
{
	char	c;

	c = map_ixy(x, y, cub3d);
	if (c == '1' || c == '2')
		return (0x000000);
	else if (y == (int)cub3d->camera.pos.y
			&& x == (int)cub3d->camera.pos.x)
		return (0x10CC10);
	else if (c == '3')
		return (0x800000);
	else if (c == '4')
		return (0xCCCCCC);
	else if (c == '5')
		return (0xFFFF00);
	return (0xFFFFFF);
}

static void
	draw_minimap(t_cub3d *cub3d, t_window *w, t_vect *start, t_vect *end)
{
	int			i;
	int			j;
	int			color;

	i = -1;
	while (++i < cub3d->map_size.y)
	{
		j = -1;
		while (++j < cub3d->map_size.x)
			if ((color = case_color(cub3d, j, i)) >= 0)
			{
				set_vect(start,
					w->size.x - (cub3d->map_size.x * 8) - 8 + (j * 8),
					w->size.y - (cub3d->map_size.y * 8) - 8 + (i * 8));
				set_vect(end,
					w->size.x - (cub3d->map_size.x * 8) + (j * 8),
					w->size.y - (cub3d->map_size.y * 8) + (i * 8));
				draw_rectangle(w, start, end, color);
			}
	}
}

void
	update_ui(t_cub3d *cub3d)
{
	t_window	*w;
	t_vect		start;
	t_vect		mid;
	t_vect		end;

	w = &cub3d->window;
	set_vect(&start, 2, w->size.y - 27);
	set_vect(&mid, 212.0 - (210.0 * (double)cub3d->frame /
		(cub3d->time * FRAME_UNIT)),
		w->size.y - 2);
	set_vect(&end, 210, w->size.y - 2);
	draw_rectangle(w, &start, &end, 0xB0B0B0);
	draw_rectangle(w, &start, &mid, 0xFF0000);
	draw_minimap(cub3d, w, &start, &end);
}
