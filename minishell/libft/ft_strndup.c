/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 14:00:44 by ijang             #+#    #+#             */
/*   Updated: 2021/02/14 14:09:00 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, int n)
{
	int		src_len;
	char	*result;

	src_len = 0;
	while (src[src_len])
		++src_len;
	if (src_len < n)
		n = src_len;
	if (!(result = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	result[n] = 0;
	while (--n > -1)
		result[n] = src[n];
	return (result);
}
