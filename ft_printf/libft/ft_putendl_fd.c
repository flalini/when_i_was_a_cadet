/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <ijang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 00:49:50 by ijang             #+#    #+#             */
/*   Updated: 2020/03/01 16:55:15 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	if (s)
	{
		i = 0;
		while (s[i])
			++i;
		write(fd, s, i);
		write(fd, "\n", 1);
	}
}
