/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 12:46:25 by ijang             #+#    #+#             */
/*   Updated: 2020/12/22 22:56:27 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static int	ft_base_check(const char *base)
{
	int		len;
	int		tmp;

	len = -1;
	while (base[++len])
	{
		if (isspace(base[len]) || base[len] == '-' || base[len] == '+')
			return (0);
		tmp = len;
		while (base[++tmp])
			if (base[tmp] == base[len])
				return (0);
	}
	return (len);
}

static int	ft_atoi_base_wc(const char *str, const char *base)
{
	int		result;
	int		neg;
	int		len;

	neg = 1;
	len = ft_base_check(base);
	if (len < 2)
		return (0);
	while (isspace(*str))
		++str;
	while (*str == '-' || *str == '+')
		if (*(str++) == '-')
			neg *= -1;
	result = 0;
	while (*str && strchr(base, *str))
	{
		result *= len;
		result += strchr(base, *(str++)) - base;
	}
	return (result * neg);
}

static void	ft_atoi_base_test_sub(char *str, char *base)
{
	int	actual;
	int	expected;

	actual = ft_atoi_base(str, base);
	expected = ft_atoi_base_wc(str, base);
	if (actual != expected)
		printf("KO expected: [%d] got: [%d] with: [%s][%s]\n",
				expected, actual, str, base);
	else
		printf("OK\n");
}

void		ft_atoi_base_test(void)
{
	printf("\nft_atoi_base test\n");
	ft_atoi_base_test_sub("", "");
	ft_atoi_base_test_sub("10", "");
	ft_atoi_base_test_sub("", "01");
	ft_atoi_base_test_sub("123", "0123456789");
	ft_atoi_base_test_sub("ffe0", "0123456789abcdef");
	ft_atoi_base_test_sub("\t\n\r\v\f\r 4", "01234");
	ft_atoi_base_test_sub("45", "0");
	ft_atoi_base_test_sub("45", "01");
	ft_atoi_base_test_sub("10", "011");
	ft_atoi_base_test_sub("10", "0+");
	ft_atoi_base_test_sub("10", "-0");
	ft_atoi_base_test_sub("10111", "\t541");
	ft_atoi_base_test_sub("10111", "98\n541");
	ft_atoi_base_test_sub("10111", "7\r541");
	ft_atoi_base_test_sub("10111", "0\v541");
	ft_atoi_base_test_sub("10111", "1\f541");
	ft_atoi_base_test_sub("10111", "54 1");
	ft_atoi_base_test_sub("111000", "01");
	ft_atoi_base_test_sub("7fffffff", "0123456789abcdef");
	ft_atoi_base_test_sub("-ff", "0123456789abcdef");
	ft_atoi_base_test_sub("-++++++-+--ff", "0123456789abcdef");
	ft_atoi_base_test_sub("-++++++-+--ff\xff", "0123456789abcdef");
	ft_atoi_base_test_sub("-+\r++-+--ff\xff", "0123456789abcdef");
	ft_atoi_base_test_sub("a\0bb", "ab");
	ft_atoi_base_test_sub("-b\0bb", "ab");
	ft_atoi_base_test_sub(" \t\n\r-++++++-+--ff\xff", "0123456789abcdef");
	ft_atoi_base_test_sub("  -+\r++-+--ff\xff", "0123456789abcdef");
	ft_atoi_base_test_sub("2147483647", "0123456789");
	ft_atoi_base_test_sub("-2147483648", "0123456789");
}
