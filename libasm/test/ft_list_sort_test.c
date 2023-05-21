/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 21:07:41 by ijang             #+#    #+#             */
/*   Updated: 2020/12/22 23:01:59 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	ft_list_sort_wc(t_list **begin_list, int (*cmp)())
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*find;

	if (!begin_list || !(*begin_list))
		return ;
	tmp = *begin_list;
	while (tmp->next)
	{
		if ((*cmp)(tmp->data, tmp->next->data) > 0)
		{
			tmp2 = tmp->next;
			tmp->next = tmp2->next;
			if ((*cmp)((*begin_list)->data, tmp2->data) > 0)
			{
				tmp2->next = *begin_list;
				*begin_list = tmp2;
			}
			else
			{
				find = *begin_list;
				while ((*cmp)(tmp2->data, find->next->data) > 0)
					find = find->next;
				tmp2->next = find->next;
				find->next = tmp2;
			}
		}
		else
			tmp = tmp->next;
	}
}

static void	ft_list_sort_test_sub(char *format)
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
	ft_list_sort_wc(&expected, ft_data_cmp);
	ft_list_sort(&actual, ft_data_cmp);
	print_list_result(from, expected, actual);
	ft_list_clear(from);
	ft_list_clear(expected);
	ft_list_clear(actual);
}

void		ft_list_sort_test(void)
{
	printf("\nft_list_sort test\n");
	ft_list_sort_test_sub("");
	ft_list_sort_test_sub("1");
	ft_list_sort_test_sub("1 2");
	ft_list_sort_test_sub("1 2 3");
	ft_list_sort_test_sub("-1 0 1 2 3 4 5 6");
	ft_list_sort_test_sub("1 2 0 3 4 5 6");
	ft_list_sort_test_sub("2 5 1 0 6 4 3 7");
	ft_list_sort_test_sub("98 12 12 45 1 -1 232 34 23");
	ft_list_sort_test_sub("12 45 1 -1 232 34 23 87879");
}
