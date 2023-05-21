/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <ijang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 16:53:55 by ijang             #+#    #+#             */
/*   Updated: 2020/03/01 18:01:10 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int c, size_t len)
{
	unsigned char	*temp;
	size_t			i;

	temp = (unsigned char *)dst;
	i = -1;
	while (++i < len)
		temp[i] = (unsigned char)c;
	return (dst);
}
