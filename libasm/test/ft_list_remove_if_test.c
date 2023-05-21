/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if_test.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 21:19:34 by ijang             #+#    #+#             */
/*   Updated: 2020/12/22 23:00:17 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	ft_free_data(void *data)
{
	free(data);
}

static void	ft_list_remove_if_wc(t_list **begin_list, void *data_ref,
					int (*cmp)(void *, void *), void (*free_fct)(void *))
{
	t_list	*current;
	t_list	*tmp;

	if (!begin_list || !(*begin_list))
		return ;
	current = *begin_list;
	while (current)
	{
		while (current->next && (*cmp)(current->next->data, data_ref) == 0)
		{
			tmp = current->next;
			current->next = tmp->next;
			free_fct(tmp->data);
			free(tmp);
		}
		current = current->next;
	}
	if ((*cmp)((*begin_list)->data, data_ref) == 0)
	{
		tmp = *begin_list;
		*begin_list = tmp->next;
		free_fct(tmp->data);
		free(tmp);
	}
}



static void	ft_list_remove_if_test_sub(char *format, int remove)
{
	t_list	*from;
	t_list	*expected;
	t_list	*actual;

	from = list_from_format(format);
	expected = list_from_format(format);
	actual = list_from_format(format);
	if (*format && (!from || !expected || !actual))
	{
		ft_list_malloc_fail(from, expected, actual);
		return ;
	}
	ft_list_remove_if_wc(&expected, &remove, ft_data_cmp, ft_free_data);
	ft_list_remove_if_wc(&actual, &remove, ft_data_cmp, ft_free_data);
	print_list_result(from, expected, actual);
	ft_list_clear(from);
	ft_list_clear(expected);
	ft_list_clear(actual);
}

void		ft_list_remove_if_test(void)
{
	printf("\nft_list_remove_if test\n");
	ft_list_remove_if_test_sub("", 0);
	ft_list_remove_if_test_sub("1", 1);
	ft_list_remove_if_test_sub("1 2", 3);
	ft_list_remove_if_test_sub("1 2 3", 3);
	ft_list_remove_if_test_sub("1 2 3", 1);
	ft_list_remove_if_test_sub("1 2 3", 2);
	ft_list_remove_if_test_sub("987 3 9812 3 12 312 3 12491234989 3 908 3", 3);
	ft_list_remove_if_test_sub("1 1 1 1 1 1 1 1", 1);
	ft_list_remove_if_test_sub("1 2 1 2 1 2 1 2", 1);
	ft_list_remove_if_test_sub("1 2 1 2 1 2 1 2", 2);
}
