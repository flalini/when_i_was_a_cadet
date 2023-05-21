/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front_test.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 22:35:31 by ijang             #+#    #+#             */
/*   Updated: 2020/12/22 23:01:26 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	ft_list_push_front_wc(t_list **begin_list, void *data)
{
	t_list	*new;

	if (!begin_list)
		return ;
	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return ;
	new->data = data;
	new->next = *begin_list;
	*begin_list = new;
}

static void	ft_list_push_front_test_sub(char *format, int push)
{
	t_list	*from;
	t_list	*expected;
	t_list	*actual;
	int		*data;

	from = list_from_format(format);
	expected = list_from_format(format);
	actual = list_from_format(format);
	if ((*format && (!from || !expected || !actual)) ||
			!(data = (int *)malloc(sizeof(int))))
	{
		ft_list_malloc_fail(from, expected, actual);
		return ;
	}
	*data = push;
	ft_list_push_front_wc(&expected, data);
	if (!list_cmp(from, expected))
	{
		free(data);
		ft_list_malloc_fail(from, expected, actual);
		return ;
	}
	if (!(data = (int *)malloc(sizeof(int))))
	{
		ft_list_malloc_fail(from, expected, actual);
		return ;
	}
	*data = push;
	ft_list_push_front(&actual, data);
	print_list_result(from, expected, actual);
	ft_list_clear(from);
	ft_list_clear(expected);
	ft_list_clear(actual);
}

void		ft_list_push_front_test(void)
{
	printf("\nft_list_push_front test\n");
	ft_list_push_front_test_sub("", 0);
	ft_list_push_front_test_sub("", 1);
	ft_list_push_front_test_sub("0", 1);
	ft_list_push_front_test_sub("1 2 3", 4);
	ft_list_push_front_test_sub("1 2 3", -1);
	ft_list_push_front_test_sub("1 2 3 4 5 6 7 8 9 10", 7);
}
