/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:47:51 by ijang             #+#    #+#             */
/*   Updated: 2020/11/16 15:36:26 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		strlst_add_back(t_strlst **start, char *text)
{
	t_strlst	*new;
	t_strlst	*tmp;

	if (!start)
		return (6);
	if (!(new = (t_strlst *)malloc(sizeof(t_strlst))))
		return (7);
	new->text = text;
	new->next = NULL;
	if (!(*start))
		*start = new;
	else
	{
		tmp = *start;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (0);
}
