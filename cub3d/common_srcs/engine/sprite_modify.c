/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_modify.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 22:08:47 by ijang             #+#    #+#             */
/*   Updated: 2020/11/15 22:14:00 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void
	modify_sprite(t_sprite **sprites, t_vect *pos, t_vect *next)
{
	t_sprite	*tmp;

	tmp = *sprites;
	while (tmp)
	{
		if ((int)tmp->pos.x == (int)pos->x
			&& (int)tmp->pos.y == (int)pos->y)
		{
			tmp->pos.x = (int)next->x + 0.5;
			tmp->pos.y = (int)next->y + 0.5;
			return ;
		}
		tmp = tmp->next;
	}
}
