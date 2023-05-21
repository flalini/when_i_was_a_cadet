/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_motion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:43:48 by ijang             #+#    #+#             */
/*   Updated: 2020/11/16 22:40:19 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_motion(t_motion *m, t_cub3d *c)
{
	m->t = &c->ani[ANI_6].tex[c->space / FRAME_UNIT];
	set_vect(&m->start,
		(int)ceil(c->window.half.x - c->window.half.y / 2.0),
		(int)ceil(c->window.half.y));
	set_vect(&m->end, m->start.x + floor(c->window.half.y), c->window.size.y);
	set_vect(&m->size, m->end.x - m->start.x, m->end.y - m->start.y);
	set_vect(&m->cal, (double)(m->t->size.x) / m->size.x,
		(double)(m->t->size.y) / m->size.y);
}

void		draw_motion(t_cub3d *cub3d)
{
	t_loca		pos;
	t_vect		cal;
	int			color;
	t_window	*w;
	t_motion	m;

	w = &cub3d->window;
	init_motion(&m, cub3d);
	m.pos.y = m.start.y;
	pos.y = -1;
	while (++(pos.y) < m.size.y)
	{
		m.pos.x = m.start.x;
		pos.x = -1;
		while (++(pos.x) < m.size.x)
		{
			set_vect(&cal, (double)pos.x * m.cal.x, (double)pos.y * m.cal.y);
			if ((color = get_color(m.t, &cal)) != EMPTY_COLOR)
				draw_pixel(w, &m.pos, color);
			m.pos.x += 1.0;
		}
		m.pos.y += 1.0;
	}
}
