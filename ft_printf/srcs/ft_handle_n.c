/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:41:39 by ijang             #+#    #+#             */
/*   Updated: 2020/09/20 21:14:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_sub_handle_n(t_form *form)
{
	short int		*hp;
	char			*hhp;

	if (form->hhll == -2)
	{
		hhp = va_arg(form->va_para, char *);
		*hhp = (char)(form->result);
	}
	else if (form->hhll == -1)
	{
		hp = va_arg(form->va_para, short int *);
		*hp = (short int)(form->result);
	}
}

int		ft_handle_n(t_form *form)
{
	long long int	*llp;
	long int		*lp;
	int				*p;

	if (form->hhll == 2)
	{
		llp = va_arg(form->va_para, long long int *);
		*llp = (long long int)(form->result);
	}
	else if (form->hhll == 1)
	{
		lp = va_arg(form->va_para, long int *);
		*lp = (long int)(form->result);
	}
	else if (form->hhll == 0)
	{
		p = va_arg(form->va_para, int *);
		*p = form->result;
	}
	else
		ft_sub_handle_n(form);
	return (0);
}
