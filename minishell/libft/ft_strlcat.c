/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <ijang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:05:23 by ijang             #+#    #+#             */
/*   Updated: 2020/03/01 17:59:28 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i])
		++i;
	while (src[j] && j + i + 1 < size)
	{
		dst[i + j] = src[j];
		++j;
	}
	dst[i + j] = 0;
	while (src[j])
		++j;
	if (i > size)
		return (j + size);
	return (j + i);
}
