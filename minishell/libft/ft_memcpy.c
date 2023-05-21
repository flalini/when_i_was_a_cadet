/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <ijang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 16:53:10 by ijang             #+#    #+#             */
/*   Updated: 2020/03/01 16:53:22 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*dst_ch;
	const char	*src_ch;

	dst_ch = (char *)dst;
	src_ch = (const char *)src;
	i = -1;
	while (++i < len)
		dst_ch[i] = src_ch[i];
	return (dst);
}
