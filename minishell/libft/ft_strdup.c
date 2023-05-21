/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 20:16:52 by ijang             #+#    #+#             */
/*   Updated: 2021/02/14 17:20:43 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		src_len;
	char	*result;

	src_len = 0;
	while (src[src_len])
		++src_len;
	if (!(result = (char *)malloc(sizeof(char) * (src_len + 1))))
		return (NULL);
	while (src_len > -1)
	{
		result[src_len] = src[src_len];
		--src_len;
	}
	return (result);
}
