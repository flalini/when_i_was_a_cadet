/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_mkf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 16:26:43 by ijang             #+#    #+#             */
/*   Updated: 2020/08/24 18:25:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_initexpput(int exp, char *put)
{
	put[0] = 'e';
	if (exp < 0)
	{
		exp *= -1;
		put[1] = '-';
	}
	else
		put[1] = '+';
	if (exp > 99)
	{
		put[2] = exp / 100 + '0';
		put[3] = (exp / 10) % 10 + '0';
		put[4] = exp % 10 + '0';
	}
	else
	{
		put[2] = exp / 10 + '0';
		put[3] = exp % 10 + '0';
	}
}

int		ft_subputfracdig(t_fraction *f, int len)
{
	int		result;

	result = 0;
	while (result < len && f->man_len)
		result += (int)write(1, f->man + --(f->man_len), 1);
	while (result < len)
		result += (int)write(1, "0", 1);
	return (result);
}

int		ft_subput_gf(t_fraction *f, int intdig, int fracdig)
{
	int	result;

	result = (int)write(1, "0.", 2);
	intdig *= -1;
	while (--intdig)
		result += (int)write(1, "0", 1);
	result += ft_subputfracdig(f, fracdig);
	return (result);
}
