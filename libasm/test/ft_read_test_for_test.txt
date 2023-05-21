/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 22:23:45 by ijang             #+#    #+#             */
/*   Updated: 2020/12/22 22:53:40 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	look_for_chars(char buffer[2][11], ssize_t *byte_read)
{
	size_t	index;

	index = 0;
	while (index < 10)
	{
		if (buffer[0][index] == '\n')
			buffer[0][index] = 'n';
		if (buffer[0][index] == '\t')
			buffer[0][index] = 't';
		if (buffer[1][index] == '\n')
			buffer[1][index] = 'n';
		if (buffer[1][index] == '\t')
			buffer[1][index] = 't';
		index++;
	}
	if (byte_read[0] <= 0)
		buffer[0][0] = '\0';
	else
		buffer[0][byte_read[0]] = '\0';
	if (byte_read[1] <= 0)
		buffer[1][0] = '\0';
	else
		buffer[1][byte_read[1]] = '\0';
}

static void	ft_read_test_err(int fd, char *s, int size)
{
	ssize_t	actual;
	int		actual_err;
	ssize_t	expected;
	int		expected_err;

	errno = 0;
	actual = ft_read(fd, s, size);
	actual_err = errno;
	errno = 0;
	expected = read(fd, s, size);
	expected_err = errno;
	if (actual != expected || actual_err != expected_err)
		printf("KO expected: [%zd][%d] got: [%zd][%d]\n",
				expected, expected_err, actual, actual_err);
	else
		printf("OK\n");
}

void		ft_read_test(void)
{
	int			fds[2];
	char		buffer[2][11];
	ssize_t		byte_read[2];
	size_t		index;

	printf("\nft_read test\n");
	fds[0] = open("test/ft_read_test.c", O_RDONLY);
	fds[1] = open("test/ft_read_test_for_test.txt", O_RDONLY);
	index = -1;
	while (++index < 32 && (byte_read[0] = read(fds[0], buffer[0], 10)))
	{
		byte_read[1] = ft_read(fds[1], buffer[1], 10);
		look_for_chars(buffer, byte_read);
		if (byte_read[0] != byte_read[1] || strcmp(buffer[0], buffer[1]))
			printf("KO expected: [%zd][%s] got: [%zd][%s]\n",
					byte_read[0], buffer[0], byte_read[1], buffer[1]);
		else
			printf("OK\n");
	}
	ft_read_test_err(fds[0], NULL, 3);
	ft_read_test_err(-1, buffer[0], 7);
	ft_read_test_err(42, buffer[0], 7);
	ft_read_test_err(42, NULL, 7);
	close(fds[0]);
	close(fds[1]);
}
