/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <ijang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 22:31:03 by ijang             #+#    #+#             */
/*   Updated: 2020/03/01 17:06:24 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;

	if (!s || !f)
		return (0);
	i = 0;
	while (s[i])
		++i;
	if (!(result = (char *)malloc((i + 1) * sizeof(char))))
		return (0);
	result[i] = 0;
	while (--i)
		result[i] = f(i, s[i]);
	result[0] = f(0, s[0]);
	return (result);
}
