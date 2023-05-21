/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 13:12:50 by ijang             #+#    #+#             */
/*   Updated: 2020/09/22 15:00:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_form	form;

	va_start(form.va_para, format);
	form.result = 0;
	if (format)
		while (*format)
		{
			if (*format != '%')
			{
				write(1, format++, 1);
				++(form.result);
			}
			else
			{
				if (!(format + 1))
				{
					va_end(form.va_para);
					return (form.result);
				}
				form.result += ft_sub_printf(&format, &form);
			}
		}
	va_end(form.va_para);
	return (form.result);
}
