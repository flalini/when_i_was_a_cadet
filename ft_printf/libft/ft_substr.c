/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <ijang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 22:42:40 by ijang             #+#    #+#             */
/*   Updated: 2020/03/01 17:41:14 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		++i;
	if (i < (size_t)start)
		len = 0;
	else
	{
		s += start;
		i = 0;
		while (s[i])
			++i;
		if (i < len)
			len = i;
	}
	if (!(substring = (char *)malloc((len + 1) * sizeof(char))))
		return (0);
	substring[len] = 0;
	while (len--)
		substring[len] = s[len];
	return (substring);
}
