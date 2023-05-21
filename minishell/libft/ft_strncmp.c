/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <ijang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 00:15:32 by ijang             #+#    #+#             */
/*   Updated: 2020/03/01 19:55:37 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	if (len)
	{
		i = 0;
		while (s1[i] != 0 && s2[i] != 0 && i < len)
		{
			if (s1[i] != s2[i])
				return ((unsigned char)s1[i] - (unsigned char)s2[i]);
			++i;
		}
		if (i != len)
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}
