/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_mk2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 18:14:05 by ijang             #+#    #+#             */
/*   Updated: 2020/09/23 17:53:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_sub_putnbr_mk2(size_t ui, int base, char *put)
{
	if (ui >= (size_t)base)
		ft_sub_putnbr_mk2(ui / (size_t)base, base, put);
	write(1, &put[ui % base], 1);
}

int		ft_uilen(size_t ui, int base)
{
	int	result;

	result = 1;
	while (ui >= (size_t)base)
	{
		++result;
		ui = ui / (size_t)base;
	}
	return (result);
}

int		ft_putnbr_mk2(size_t ui, char *put, int base, t_form *form)
{
	int	result;
	int	i;

	result = 0;
	i = ft_uilen(ui, base);
	if (form->width > 0 && !form->ladjust)
		while (form->width--)
			result += (int)write(1, put, 1);
	if ((int)form->put_width > i)
		while ((int)form->put_width != i)
			i += (int)write(1, put, 1);
	ft_sub_putnbr_mk2(ui, base, put);
	return (result + i);
}
