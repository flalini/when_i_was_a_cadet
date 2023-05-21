/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <ijang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 23:52:58 by ijang             #+#    #+#             */
/*   Updated: 2020/08/08 17:37:09 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (0);
	s1_len = 0;
	s2_len = 0;
	while (s1[s1_len])
		++s1_len;
	while (s2[s2_len])
		++s2_len;
	if (!(result = (char *)malloc((s1_len + s2_len + 1) * sizeof(char))))
		return (0);
	result[s1_len + s2_len] = 0;
	if (s2_len)
		while (--s2_len)
			result[s1_len + s2_len] = s2[s2_len];
	result[s1_len] = s2[0];
	if (s1_len)
		while (--s1_len)
			result[s1_len] = s1[s1_len];
	if (s1[0])
		result[0] = s1[0];
	return (result);
}
