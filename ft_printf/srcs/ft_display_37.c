/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_37.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <ijang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 00:24:58 by ijang             #+#    #+#             */
/*   Updated: 2020/08/09 19:26:57 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_display_37(t_form *form)
{
	int		result;

	result = 0;
	if (!form->ladjust)
		while (--(form->width) > 0)
			result += (int)write(1, form->padc, 1);
	result += (int)write(1, "%", 1);
	while (--(form->width) > 0)
		result += (int)write(1, " ", 1);
	return (result);
}
