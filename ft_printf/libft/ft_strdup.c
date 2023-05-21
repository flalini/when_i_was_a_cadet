/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <ijang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 20:16:52 by ijang             #+#    #+#             */
/*   Updated: 2020/03/01 17:37:19 by ijang            ###   ########.fr       */
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
	result = (char *)malloc(sizeof(char) * (src_len + 1));
	while (src_len > -1)
	{
		result[src_len] = src[src_len];
		--src_len;
	}
	return (result);
}
