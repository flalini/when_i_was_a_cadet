/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:58:59 by ijang             #+#    #+#             */
/*   Updated: 2021/02/20 17:00:52 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		exit_cmd3(t_minishell *minishell, int status)
{
	ft_strdel(&minishell->name);
	ft_strdel(&minishell->curdir);
	ft_strdel(&minishell->line);
	ft_strdel(&minishell->exit_str);
	clear_cmd_list(&minishell->cmd_list, free);
	ft_lstclear(&minishell->env_list, free_env2);
	clear_token_list(&minishell->token_list, free);
	ft_free_split(&minishell->env_array);
	ft_free_split(&minishell->bin);
	exit(status);
}

int			exit_status(t_minishell *minishell, t_cmd *cmd)
{
	if (cmd->args)
	{
		if (is_numeric_arg(((t_token*)cmd->args)->word))
			minishell->exit = ft_atoi(((t_token*)cmd->args)->word);
		else
		{
			ft_dprintf(2, "%s: %s: %s: %s\n", minishell->name, cmd->cmd,
				((t_token*)cmd->args)->word, "numeric argument required");
			minishell->exit = 255;
		}
	}
	return ((int)minishell->exit);
}

void		exit_cmd2(t_minishell *minishell, t_cmd *cmd, int ex)
{
	int		exit_s;

	exit_s = 0;
	!ex ? ft_dprintf(2, "exit\n") : 0;
	if (token_list_size(&cmd->args) > 1)
	{
		ft_dprintf(2, "%s: %s: %s\n", minishell->name, cmd->cmd,
			"too many arguments");
		minishell->exit = 1;
		return ;
	}
	exit_s = exit_status(minishell, cmd);
	exit_cmd3(minishell, exit_s);
}

void		exit_cmd4(t_minishell *minishell)
{
	ft_dprintf(2, "exit\n");
	exit_cmd3(minishell, minishell->exit);
}

void		exit_cmd(t_minishell *minishell)
{
	exit_cmd3(minishell, 1);
}
