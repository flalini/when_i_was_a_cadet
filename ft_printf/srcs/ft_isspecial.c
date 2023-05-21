/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspecial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 17:51:01 by ijang             #+#    #+#             */
/*   Updated: 2020/08/15 17:20:55 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isnan(double d)
{
	int64_t tmp;

	tmp = *(int64_t *)(&d);
	tmp &= 0x7fffffffffffffff;
	tmp = 0x7ff0000000000000 - tmp;
	return ((int)(((uint64_t)tmp) >> 63));
}

int	ft_display_nan(t_form *form)
{
	int	result;

	result = 0;
	if (!form->ladjust)
		while (form->width-- > 0)
			result += (int)write(1, " ", 1);
	result += (int)write(1, "nan", 3);
	while (form->width-- > 0)
		result += (int)write(1, " ", 1);
	return (result);
}

int	ft_display_inf(t_form *form)
{
	int	result;

	result = 0;
	if (!form->ladjust)
		while (form->width-- > 0)
			result += (int)write(1, " ", 1);
	if (form->sign)
		result += (int)write(1, &form->sign, 1);
	result += (int)write(1, "inf", 3);
	while (form->width-- > 0)
		result += (int)write(1, " ", 1);
	return (result);
}

int	ft_isspecial(double d, t_form *form)
{
	if (ft_isnan(d))
	{
		form->width -= 3;
		return (ft_display_nan(form));
	}
	if (d == INFINITY || d == -INFINITY)
	{
		if (d == -INFINITY)
			form->sign = '-';
		form->width -= 3 + (form->sign ? 1 : 0);
		return (ft_display_inf(form));
	}
	return (0);
}
