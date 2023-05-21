/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_remove_if.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 00:13:13 by ijang             #+#    #+#             */
/*   Updated: 2021/02/18 02:17:50 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_lst_remove_if(t_list **begin_list, void *data_ref,
			int (*cmp)(), void (*del)())
{
	t_list	*current;
	t_list	*tmp;

	if (!begin_list || !(*begin_list))
		return ;
	current = *begin_list;
	while (current)
	{
		while (current->next && (*cmp)(current->next->content, data_ref) == 0)
		{
			tmp = current->next;
			current->next = tmp->next;
			del(tmp);
		}
		current = current->next;
	}
	if ((*cmp)((*begin_list)->content, data_ref) == 0)
	{
		tmp = *begin_list;
		*begin_list = tmp->next;
		del(tmp);
	}
}
