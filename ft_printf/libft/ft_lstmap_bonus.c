/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <ijang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 15:33:46 by ijang             #+#    #+#             */
/*   Updated: 2020/03/01 15:45:29 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*first;

	if (!lst || !(newlist = ft_lstnew(f(lst->content))))
		return (0);
	first = newlist;
	while (lst->next)
	{
		if (!(newlist->next = ft_lstnew(f(lst->next->content))))
		{
			ft_lstclear(&first, del);
			return (0);
		}
		newlist = newlist->next;
		lst = lst->next;
	}
	return (first);
}
