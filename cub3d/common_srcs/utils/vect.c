/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:48:59 by ijang             #+#    #+#             */
/*   Updated: 2020/11/15 20:56:21 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_vect(t_vect *vect, double x, double y)
{
	vect->x = x;
	vect->y = y;
}

void	copy_vect(t_vect *vect, t_vect *org)
{
	vect->x = org->x;
	vect->y = org->y;
}
