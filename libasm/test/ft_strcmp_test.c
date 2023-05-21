/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 21:02:10 by ijang             #+#    #+#             */
/*   Updated: 2020/12/20 21:48:10 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	ft_strcmp_test_sub(char *s1, char *s2)
{
	int	actual;
	int	expected;

	actual = ft_strcmp(s1, s2);
	expected = strcmp(s1, s2);
	if (actual == expected || (actual < 0 && expected < 0) ||
			(actual > 0 && expected > 0))
		printf("OK\n");
	else
		printf("KO expected: [%d] got: [%d] with: [%s] [%s]\n",
				expected, actual, s1, s2);
	actual = ft_strcmp(s2, s1);
	expected = strcmp(s2, s1);
	if (actual == expected || (actual < 0 && expected < 0) ||
			(actual > 0 && expected > 0))
		printf("OK\n");
	else
		printf("KO expected: [%d] got: [%d] with: [%s] [%s]\n",
				expected, actual, s1, s2);
}

void		ft_strcmp_test(void)
{
	printf("\nft_strcmp test\n");
	ft_strcmp_test_sub("", "");
	ft_strcmp_test_sub("bon", "");
	ft_strcmp_test_sub("bon", "bon");
	ft_strcmp_test_sub("bonjour", "");
	ft_strcmp_test_sub("bonjour", "bonjour");
	ft_strcmp_test_sub("asdklfjasdfj////asdf'''asdf3##", "");
	ft_strcmp_test_sub("asdklfjasdfj////asdf'''asdf3##", "asdklfjasdfj////asdf'''asdf3##");
	ft_strcmp_test_sub("the\0hidden", "");
	ft_strcmp_test_sub("the\0hidden", "the\0hidden");
	ft_strcmp_test_sub("", "asdf");
	ft_strcmp_test_sub("bon", "bo");
	ft_strcmp_test_sub("bonjour", "onjour");
	ft_strcmp_test_sub("\x01", "\x01");
	ft_strcmp_test_sub("\x02", "\x01");
	ft_strcmp_test_sub("\xff", "\xff");
	ft_strcmp_test_sub("\xfe", "\xff");
	ft_strcmp_test_sub("\x01\x01", "\x01");
	ft_strcmp_test_sub("\x01\x02", "\x01");
	ft_strcmp_test_sub("\x02\x01", "\x02");
	ft_strcmp_test_sub("\xff\xff", "\xff");
	ft_strcmp_test_sub("\xff\xfe", "\xff");
	ft_strcmp_test_sub("\xfe\xff", "\xfe");
}
