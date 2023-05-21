/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <ijang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 16:52:23 by ijang             #+#    #+#             */
/*   Updated: 2020/03/01 16:52:38 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*temp;

	i = -1;
	temp = (unsigned char *)b;
	while (++i < len)
		if (temp[i] == (unsigned char)c)
			return (&temp[i]);
	return (0);
}
