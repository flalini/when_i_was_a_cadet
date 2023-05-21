/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 22:10:25 by ijang             #+#    #+#             */
/*   Updated: 2021/02/20 13:24:47 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	char	*str;

	if (!s2)
	{
		if (!s1)
			return (NULL);
		str = ft_strdup(s1);
		free((void*)s1);
		return (str);
	}
	else if (!s1)
	{
		str = ft_strdup(s2);
		return (str);
	}
	if (!(str = (char *)ft_calloc(1, sizeof(char)
		* (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	ft_strcpy(str, s1);
	free((void *)s1);
	ft_strcat(str, s2);
	return (str);
}
