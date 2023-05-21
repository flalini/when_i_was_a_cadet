/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <ijang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 16:52:48 by ijang             #+#    #+#             */
/*   Updated: 2020/03/01 16:53:01 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	if (len == 0)
		return (0);
	str1 = (unsigned char *)b1;
	str2 = (unsigned char *)b2;
	i = -1;
	while (++i < len)
		if (str1[i] != str2[i])
			return ((int)(str1[i] - str2[i]));
	return (0);
}
