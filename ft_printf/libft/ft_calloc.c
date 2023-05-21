/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <ijang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 17:19:54 by ijang             #+#    #+#             */
/*   Updated: 2020/03/01 16:47:44 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	char	*result;
	size_t	i;
	size_t	limit;

	if (number && size)
	{
		limit = number * size;
		if (limit % size != 0 || limit / size != number)
		{
			errno = ENOMEM;
			return (0);
		}
	}
	else
		limit = 1;
	result = (char *)malloc(limit);
	if (result)
	{
		i = -1;
		while (++i < limit)
			result[i] = 0;
	}
	return (result);
}
