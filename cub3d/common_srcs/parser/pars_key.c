/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 21:24:28 by ijang             #+#    #+#             */
/*   Updated: 2020/11/17 19:10:12 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		pars_key(char *l)
{
	if (l[0] == 'R' && l[1] == ' ')
		return (P_R);
	else if (l[0] == 'N' && l[1] == 'O')
		return (P_NO);
	else if (l[0] == 'S' && l[1] == 'O')
		return (P_SO);
	else if (l[0] == 'W' && l[1] == 'E')
		return (P_WE);
	else if (l[0] == 'E' && l[1] == 'A')
		return (P_EA);
	else if (l[0] == 'F' && l[1] == 'T')
		return (P_FT);
	else if (l[0] == 'C' && l[1] == 'T')
		return (P_CT);
	else if (l[0] == 'S' && l[1] == ' ')
		return (P_S);
	else if (l[0] == 'F' && l[1] == ' ')
		return (P_F);
	else if (l[0] == 'C' && l[1] == ' ')
		return (P_C);
	else if (l[0] == 'A' && l[1] >= '3' && l[1] <= '6' && l[2] == ' ')
		return (P_S + l[1] - '2');
	else if (l[0] == 'T' && l[1] == ' ')
		return (P_T);
	return (P_MAP);
}
