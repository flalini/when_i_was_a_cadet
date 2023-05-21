/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 17:47:19 by ijang             #+#    #+#             */
/*   Updated: 2020/12/20 21:18:11 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	ft_strlen_test(void)
{
	int	i;
	int	actual;
	int	expected;

	i = -1;
	printf("\nft_strlen test\n");
	while (g_strings[++i])
	{
		actual = ft_strlen(g_strings[i]);
		expected = strlen(g_strings[i]);
		if (actual != expected)
			printf("KO expected: [%d] got: [%d] with: [%s]\n",
					expected, actual, g_strings[i]);
		else
			printf("OK\n");
	}
}
