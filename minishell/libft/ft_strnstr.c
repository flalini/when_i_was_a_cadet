/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <ijang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 23:47:11 by ijang             #+#    #+#             */
/*   Updated: 2020/08/08 17:37:48 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;

	if (!*little)
		return ((char *)big);
	little_len = 0;
	while (little[little_len])
		little_len++;
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (j < little_len && i + j < len)
		{
			if (big[i + j] != little[j])
				break ;
			++j;
		}
		if (!little[j] && big[i + j - 1] == little[j - 1])
			return ((char *)&big[i]);
		++i;
	}
	return (0);
}
