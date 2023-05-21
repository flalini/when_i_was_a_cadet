/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 12:43:21 by ijang             #+#    #+#             */
/*   Updated: 2020/12/22 22:01:17 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	ft_strdup_test(void)
{
	int		i;
	char	*actual;

	i = -1;
	printf("\nft_strdup test\n");
	while (g_strings[++i])
	{
		if (!(actual = ft_strdup(g_strings[i])))
		{
			printf("malloc fail\n");
			return ;
		}
		if (strcmp(actual, g_strings[i]))
			printf("KO expected: [%s] got: [%s]\n",
					g_strings[i], actual);
		else
			printf("OK\n");
		free(actual);
	}
}
