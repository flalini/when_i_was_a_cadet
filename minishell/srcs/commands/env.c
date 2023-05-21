/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 11:21:25 by ijang             #+#    #+#             */
/*   Updated: 2021/02/16 12:14:39 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_cmd(t_list **begin)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *begin;
	if (!*begin)
		return ;
	while (tmp)
	{
		if (((t_env*)(tmp->content))->value && !((t_env*)(tmp->content))->tmp)
			printf("%s=%s\n", ((t_env*)(tmp->content))->name,
				((t_env*)(tmp->content))->value);
		tmp = tmp->next;
	}
}
