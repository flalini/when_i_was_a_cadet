/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_double_free.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 17:14:40 by ijang             #+#    #+#             */
/*   Updated: 2021/02/14 17:25:18 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_double_free(char const *s1, char const *s2)
{
	char	*str;

	if (!s2)
		s2 = s1;
	if (!s1)
		s1 = s2;
	if (s1 == s2)
	{
		if (!s1)
			return (NULL);
		str = ft_strdup(s1);
		free((void*)s1);
		return (str);
	}
	if (!(str = (char *)ft_calloc(1, sizeof(char)
		* (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	ft_strcpy(str, s1);
	free((void*)s1);
	ft_strcat(str, s2);
	free((void*)s2);
	return (str);
}
