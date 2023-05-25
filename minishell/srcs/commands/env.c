/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <flan101544@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 11:21:25 by ijang             #+#    #+#             */
/*   Updated: 2023/05/25 14:51:44 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_cmd(t_list **begin)
{
	t_list	*tmp;

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
