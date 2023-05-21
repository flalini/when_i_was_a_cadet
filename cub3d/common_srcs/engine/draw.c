/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 22:55:30 by ijang             #+#    #+#             */
/*   Updated: 2020/11/13 23:07:20 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		draw_pixel(t_window *w, t_vect *pos, int color)
{
	if (pos->x >= 0.0 && pos->x < (double)w->size.x
		&& pos->y >= 0.0 && pos->y < (double)w->size.y)
		w->screen.data[(w->size.x * (int)pos->y) + (int)pos->x] = color;
}

int			draw_vertical_line(t_window *win, t_vect *s, int len, int c)
{
	int		i;
	int		j;
	t_vect	pos;
	int		limit;

	if (s->x < 0 || s->x > win->size.x)
		return (1);
	pos.x = s->x;
	limit = (int)win->size.y;
	i = 0;
	while (i < len && (j = s->y + i) < limit)
	{
		pos.y = j;
		draw_pixel(win, &pos, c);
		i++;
	}
	return (1);
}

static void	restrain_pos(t_vect *pos, t_loca *size)
{
	if (pos->x < 0)
		pos->x = 0;
	if (pos->x > size->x)
		pos->x = size->x - 1;
	if (pos->y < 0)
		pos->y = 0;
	if (pos->y > size->y)
		pos->y = size->y - 1;
}

int			draw_rectangle(t_window *win, t_vect *p1, t_vect *p2, int color)
{
	int		i;
	int		j;
	t_vect	pos;

	restrain_pos(p1, &win->size);
	restrain_pos(p2, &win->size);
	i = p1->y;
	while (i < p2->y)
	{
		pos.y = i;
		j = p1->x;
		while (j < p2->x)
		{
			pos.x = j++;
			draw_pixel(win, &pos, color);
		}
		i++;
	}
	return (1);
}
