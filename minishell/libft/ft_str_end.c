/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:15:57 by ijang             #+#    #+#             */
/*   Updated: 2021/02/20 13:11:02 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_end(char *str, char *end)
{
	int		i;
	int		j;

	if (!str || !end)
		return (0);
	i = ft_strlen(str) - 1;
	j = ft_strlen(end) - 1;
	if (i < j)
		return (0);
	while (str[i] && end[j])
	{
		if (str[i] != end[j])
			return (0);
		j--;
		i--;
	}
	return (1);
}
