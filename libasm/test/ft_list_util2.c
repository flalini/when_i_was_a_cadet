/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_util2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 23:12:45 by ijang             #+#    #+#             */
/*   Updated: 2020/12/22 21:20:27 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int		ft_data_cmp(void *d1, void *d2)
{
	return (*((int *)d1) - *((int *)d2));
}

void	list_print(t_list *list)
{
	if (!list)
	{
		printf("NULL");
		return ;
	}
	while (list)
	{
		printf("[%d] -> ", *((int *)(list->data)));
		list = list->next;
	}
	printf("[NULL]");
}

void	print_list_result(t_list *from, t_list *expected, t_list *actual)
{
	if (list_cmp(expected, actual))
	{
		printf("KO: expected: ");
		list_print(expected);
		printf(" got: ");
		list_print(actual);
		printf(" with: ");
		list_print(from);
		printf("\n");
	}
	else
		printf("OK\n");
}
