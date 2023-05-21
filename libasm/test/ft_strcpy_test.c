/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 18:12:56 by ijang             #+#    #+#             */
/*   Updated: 2020/12/22 21:51:21 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	ft_strcpy_test(void)
{
	int		i;
	char	*actual;

	i = -1;
	printf("\nft_strcpy test\n");
	while (g_strings[++i])
	{
		if (!(actual = malloc(strlen(g_strings[i]) + 1)))
		{
			printf("malloc fail\n");
			return ;
		}
		actual = ft_strcpy(actual, g_strings[i]);
		if (strcmp(actual, g_strings[i]))
			printf("KO expected: [%s] got: [%s]\n",
					g_strings[i], actual);
		else
			printf("OK\n");
		free(actual);
	}
}
