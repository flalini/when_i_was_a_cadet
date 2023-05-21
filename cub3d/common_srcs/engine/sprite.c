/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 00:01:17 by ijang             #+#    #+#             */
/*   Updated: 2020/11/18 13:06:30 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void
	init_draw_sprite(t_cub3d *cub3d, t_sprite *sprite, double inv_det,
		t_sprite_draw *spr)
{
	set_vect(&spr->pos, sprite->pos.x - cub3d->camera.pos.x,
				sprite->pos.y - cub3d->camera.pos.y);
	set_vect(&spr->transform,
		inv_det * (cub3d->camera.dir.y * spr->pos.x
					- cub3d->camera.dir.x * spr->pos.y),
		inv_det * (-cub3d->camera.plane.y * spr->pos.x
					+ cub3d->camera.plane.x * spr->pos.y));
	spr->sprite_screen = (int)(cub3d->window.half.x
						* (1.0 + spr->transform.x / spr->transform.y));
	spr->spr_s.x = fabs((double)cub3d->window.size.y / spr->transform.y);
	spr->spr_s.y = fabs((double)cub3d->window.size.y / spr->transform.y);
	set_vect(&spr->draw_x,
		(int)((0 > -spr->spr_s.x / 2. + spr->sprite_screen) ?
			(0) : (-spr->spr_s.x / 2. + spr->sprite_screen)),
		(int)((0 > spr->spr_s.x / 2. + spr->sprite_screen) ?
			(0) : (spr->spr_s.x / 2. + spr->sprite_screen)));
	set_vect(&spr->draw_y,
		(int)((0 > -spr->spr_s.y / 2. + cub3d->window.half.y) ?
			(0) : -spr->spr_s.y / 2. + cub3d->window.half.y),
		(int)((0 > spr->spr_s.y / 2. + cub3d->window.half.y) ?
			(0) : (spr->spr_s.y / 2. + cub3d->window.half.y)));
	spr->draw_y_org = spr->draw_y.x;
}

static int
	set_tex_pos(t_cub3d *cub3d, t_sprite_draw *spr, t_tex *tex,
		t_vect *tex_pos)
{
	tex_pos->x = (int)(256
		* (((int)(spr->draw_x.x) - (-spr->spr_s.x / 2.0 + spr->sprite_screen)))
			* (double)tex->size.x / spr->spr_s.x) / 256;
	if (tex_pos->x < (double)tex->start.x || tex_pos->x > (double)tex->end.x)
		return (0);
	spr->fact = ((int)(spr->draw_y.x) * 256.0) - (cub3d->window.size.y * 128.0)
		+ (spr->spr_s.y * 128.0);
	tex_pos->y = ((spr->fact * (double)tex->size.y) / spr->spr_s.y) / 256.0;
	return (tex_pos->y > (double)tex->start.y &&
		tex_pos->y < (double)tex->end.y);
}

static void
	draw_sprite_pixel(t_cub3d *cub3d, t_sprite *sprite, t_sprite_draw *spr,
		t_tex *tex)
{
	t_vect	pixel;
	t_vect	tex_pos;
	int		color;

	set_vect(&pixel, spr->draw_x.x, spr->draw_y.x);
	if (set_tex_pos(cub3d, spr, tex, &tex_pos))
	{
		color = get_color(tex, &tex_pos);
		if (color != EMPTY_COLOR)
			draw_pixel(&cub3d->window, &pixel, shade_color(color,
			(cub3d->option & FLAG_SHADOWS) ? sprite->distance / 3 : 1));
	}
}

static void
	draw_sprite(t_cub3d *cub3d, t_sprite *sprite, t_sprite_draw *spr,
		t_tex *tex)
{
	while (spr->draw_x.x < cub3d->window.size.x
		&& spr->draw_x.x < spr->draw_x.y)
	{
		if (spr->transform.y > 0.0
			&& spr->transform.y < cub3d->depth[(int)spr->draw_x.x])
		{
			spr->draw_y.x = spr->draw_y_org;
			while (spr->draw_y.x < (double)cub3d->window.size.y
				&& spr->draw_y.x < spr->draw_y.y)
			{
				draw_sprite_pixel(cub3d, sprite, spr, tex);
				spr->draw_y.x++;
			}
		}
		spr->draw_x.x++;
	}
}

void
	draw_sprites(t_cub3d *cub)
{
	int				frame;
	t_sprite		*sorted;
	double			inv_det;
	t_sprite_draw	spr;

	inv_det = 1.0 / ((cub->camera.plane.x * cub->camera.dir.y)
				- (cub->camera.plane.y * cub->camera.dir.x));
	sorted = sort_sprites(cub, cub->sprite);
	frame = cub->frame / FRAME_UNIT;
	while (sorted)
	{
		if (sorted->distance > 0.1)
		{
			init_draw_sprite(cub, sorted, inv_det, &spr);
			draw_sprite(cub, sorted, &spr,
				&sorted->ani[frame % sorted->count]);
		}
		sorted = sorted->sorted;
	}
}
