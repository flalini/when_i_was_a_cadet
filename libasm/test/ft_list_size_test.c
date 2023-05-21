/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:30:16 by ijang             #+#    #+#             */
/*   Updated: 2020/12/22 23:00:59 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static int	ft_list_size_wc(t_list *begin_list)
{
	int		result;

	result = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		++result;
	}
	return (result);
}

static void	ft_list_size_test_sub(char *format)
{
	t_list	*from;
	int		expected;
	int		actual;

	from = list_from_format(format);
	expected = ft_list_size_wc(from);
	actual = ft_list_size(from);
	if (*format && !from)
	{
		ft_list_malloc_fail(from, NULL, NULL);
		return ;
	}
	if (expected != actual)
	{
		printf("KO: expected: [%d] got: [%d] with: ", expected, actual);
		list_print(from);
		printf("\n");
	}
	else
		printf("OK\n");
	ft_list_clear(from);
}


void		ft_list_size_test(void)
{
	printf("\nft_list_size test\n");
	ft_list_size_test_sub("");
	ft_list_size_test_sub("0");
	ft_list_size_test_sub("1 2 3");
	ft_list_size_test_sub("1 2 3 4 5 6 7 8 9 10");
	ft_list_size_test_sub("1 2 3 4 10");
	ft_list_size_test_sub("19879 123 12344");
	ft_list_size_test_sub("1");
	ft_list_size_test_sub("1 2");
	ft_list_size_test_sub("0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19");
}
