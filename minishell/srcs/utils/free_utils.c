/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 12:56:43 by ijang             #+#    #+#             */
/*   Updated: 2021/02/17 16:55:32 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_cmd(void *cmd)
{
	t_cmd	*tmp;

	tmp = cmd;
	ft_strdel(&tmp->cmd);
	free(cmd);
}

void	free_env(void *lst)
{
	t_env	*env;

	env = ((t_list*)lst)->content;
	if (env->name)
		ft_strdel(&env->name);
	if (env->value)
		ft_strdel(&env->value);
	free(env);
	free(lst);
}

void	free_env2(void *lst)
{
	t_env	*env;

	env = lst;
	ft_strdel(&env->name);
	ft_strdel(&env->value);
	free(env);
}

void	free_redirect(t_token *tmp)
{
	ft_strdel(&tmp->word);
	free(tmp);
}

void	nothing(void *cmd)
{
	(void)cmd;
}
