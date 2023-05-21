/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 11:27:20 by ijang             #+#    #+#             */
/*   Updated: 2021/02/18 01:18:16 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_putnbr_mk3(long int i, char *put)
{
	if (i >= 10)
		ft_putnbr_mk3(i / 10, put);
	write(1, &put[i % 10], 1);
}

static void	print_d(int fd, long int i)
{
	if (i < 0)
	{
		write(fd, "-", 1);
		i *= -1;
	}
	ft_putnbr_mk3(i, "0123456789");
}

static void	print_s(int fd, char *str)
{
	write(fd, str, ft_strlen(str));
}

void		ft_dprintf(int fd, const char *str, ...)
{
	va_list	ap;

	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			++str;
			if (!(*str))
				break ;
			if (*str == 's')
				print_s(fd, va_arg(ap, char *));
			else
				print_d(fd, (long int)va_arg(ap, int));
		}
		else
			write(fd, str, 1);
		++str;
	}
	va_end(ap);
}
