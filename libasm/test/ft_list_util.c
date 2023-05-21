/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 21:41:07 by ijang             #+#    #+#             */
/*   Updated: 2020/12/22 22:03:51 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

t_list	*ft_list_clear(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		free(list->data);
		tmp = list;
		list = list->next;
		free(tmp);
	}
	return (NULL);
}

void	ft_list_malloc_fail(t_list *l1, t_list *l2, t_list *l3)
{
	ft_list_clear(l1);
	ft_list_clear(l2);
	ft_list_clear(l3);
	printf("malloc fali\n");
}

int		list_cmp(t_list *l1, t_list *l2)
{
	while (l1 && l2)
	{
		if (*((int *)(l1->data)) != *((int *)(l2->data)))
			return (-1);
		l1 = l1->next;
		l2 = l2->next;
	}
	if (l1 || l2)
		return (-1);
	return (0);
}

t_list	*list_from_format(char *format)
{
	t_list	*start;
	t_list	*current;

	if (!format || !(*format))
		return (NULL);
	if (!(start = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	start->next = NULL;
	if (!(start->data = malloc(sizeof(int))))
		return (ft_list_clear(start));
	*((int *)(start->data)) = (int)strtol(format, &format, 10);
	current = start;
	while (*format)
	{
		if (!(current->next = (t_list *)malloc(sizeof(t_list))))
			return (ft_list_clear(start));
		current = current->next;
		current->next = NULL;
		if (!(current->data = malloc(sizeof(int))))
			return (ft_list_clear(start));
		*((int *)(current->data)) = (int)strtol(format, &format, 10);
	}
	return (start);
}
