/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 18:44:10 by ijang             #+#    #+#             */
/*   Updated: 2021/02/16 18:49:39 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_errno(t_minishell *minishell, char *cmd, int type)
{
	if (type == 14)
		ft_dprintf(2, "%s: %s: %s\n", minishell->name, cmd,
			"command not found");
	else
		ft_dprintf(2, "%s: %s: %s\n", minishell->name, cmd, strerror(errno));
	minishell->exit = 127;
}
