/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loca.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 19:30:14 by ijang             #+#    #+#             */
/*   Updated: 2020/11/14 17:55:16 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_loca(t_loca *loca, int x, int y)
{
	loca->x = x;
	loca->y = y;
}

void	copy_loca(t_loca *loca, t_loca *org)
{
	loca->x = org->x;
	loca->y = org->y;
}
