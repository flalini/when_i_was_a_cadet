/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <ijang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:07:04 by ijang             #+#    #+#             */
/*   Updated: 2020/08/08 17:39:11 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*result;

	result = 0;
	while (*s)
	{
		if (*s == (char)c)
			result = (char *)s;
		++s;
	}
	if (c)
		return (result);
	result = (char *)s;
	return (result);
}
