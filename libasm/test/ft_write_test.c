/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 21:17:33 by ijang             #+#    #+#             */
/*   Updated: 2020/12/22 21:54:20 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	ft_write_test_sub(char *s)
{
	ssize_t	actual;
	int		actual_err;
	ssize_t	expected;
	int		expected_err;

	errno = 0;
	actual = ft_write(0, s, strlen(s));
	actual_err = errno;
	write(0, "\n", 1);
	errno = 0;
	expected = write(0, s, strlen(s));
	expected_err = errno;
	write(0, "\n", 1);
	if (actual != expected || actual_err != expected_err)
		printf("KO expected: [%zd][%d] got: [%zd][%d] with: [%s]\n",
				expected, expected_err, actual, actual_err, s);
	else
		printf("OK?\n");
}

static void	ft_write_test_err(int fd, char *s, int size)
{
	ssize_t	actual;
	int		actual_err;
	ssize_t	expected;
	int		expected_err;

	errno = 0;
	actual = ft_write(fd, s, size);
	actual_err = errno;
	errno = 0;
	expected = write(fd, s, size);
	expected_err = errno;
	if (actual != expected || actual_err != expected_err)
		printf("KO expected: [%zd][%d] got: [%zd][%d]\n",
				expected, expected_err, actual, actual_err);
	else
		printf("OK\n");
}

void	ft_write_test(void)
{
	int		i;

	i = 0;
	printf("\nft_write test\n");
	while (g_strings[++i])
		ft_write_test_sub(g_strings[i]);
	ft_write_test_err(STDOUT_FILENO, NULL, 3);
	ft_write_test_err(-1, "bonjour", 7);
	ft_write_test_err(42, "bonjour", 7);
	ft_write_test_err(9809, "bonjour", 7);
	ft_write_test_err(98123, "", 1);
	ft_write_test_err(42, NULL, 7);
}
