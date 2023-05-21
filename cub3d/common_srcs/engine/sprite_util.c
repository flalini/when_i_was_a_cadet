/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 22:09:21 by ijang             #+#    #+#             */
/*   Updated: 2020/11/16 18:58:42 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int
	add_front_sprite(t_sprite **start, t_vect *pos, int count, t_tex *tex)
{
	t_sprite	*new;

	if (!(new = (t_sprite *)malloc(sizeof(t_sprite))))
		return (0);
	copy_vect(&new->pos, pos);
	new->distance = 0.0;
	new->ani = tex;
	new->count = count;
	new->next = *start;
	*start = new;
	return (1);
}

t_sprite
	*add_sorted_sprite(t_sprite **sorted, t_sprite *sprite)
{
	t_sprite	*first;
	t_sprite	*previous;

	if (!*sorted)
		return ((*sorted = sprite));
	first = *sorted;
	previous = NULL;
	while (*sorted && sprite->distance < (*sorted)->distance)
	{
		previous = *sorted;
		*sorted = (*sorted)->sorted;
	}
	if (!previous)
	{
		sprite->sorted = *sorted;
		*sorted = sprite;
	}
	else
	{
		sprite->sorted = previous->sorted;
		previous->sorted = sprite;
		*sorted = first;
	}
	return (sprite);
}

t_sprite
	*sort_sprites(t_cub3d *cub3d, t_sprite *sprites)
{
	t_sprite	*sorted;
	t_vect		p;

	sorted = NULL;
	copy_vect(&p, &cub3d->camera.pos);
	while (sprites)
	{
		sprites->distance =
			fabs(((p.x - sprites->pos.x) * (p.x - sprites->pos.x)
				+ (p.y - sprites->pos.y) * (p.y - sprites->pos.y)));
		sprites->sorted = NULL;
		add_sorted_sprite(&sorted, sprites);
		sprites = sprites->next;
	}
	return (sorted);
}

void
	delete_sprite(t_sprite **sprites, t_vect *pos)
{
	t_sprite	*tmp;
	t_sprite	*previous;
	t_sprite	*first;

	first = *sprites;
	previous = NULL;
	while (*sprites)
	{
		if ((int)(*sprites)->pos.x == (int)pos->x
			&& (int)(*sprites)->pos.y == (int)pos->y)
		{
			tmp = *sprites;
			if (!previous)
				*sprites = tmp->next;
			else
				previous->next = tmp->next;
			free(tmp);
			if (previous)
				*sprites = first;
			return ;
		}
		previous = *sprites;
		*sprites = (*sprites)->next;
	}
	*sprites = first;
}

void
	clear_sprites(t_sprite **sprites)
{
	t_sprite	*tmp;

	while (*sprites)
	{
		tmp = (*sprites)->next;
		free(*sprites);
		*sprites = tmp;
	}
}
