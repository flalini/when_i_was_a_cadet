/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:56:22 by ijang             #+#    #+#             */
/*   Updated: 2021/02/17 18:45:10 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sighandler(int sig_num)
{
	printf("\b\b  \b\b");
	if (sig_num == SIGINT)
	{
		printf("\n");
		if (!g_minishell->forked)
			g_minishell->exit = 1;
		else
			g_minishell->exit = 130;
		print_prompt(g_minishell);
		g_minishell->quit = 1;
	}
	if (sig_num == SIGQUIT)
		g_minishell->quit = 4;
}

void	degage_frr(int sig_num)
{
	if (sig_num == 3)
		ft_dprintf(2, "Quit: %d\n", sig_num);
	g_minishell->quit = 4;
	g_minishell->quit2 = 1;
	if (sig_num == SIGQUIT)
		g_minishell->exit = 131;
	if (sig_num == SIGINT)
	{
		g_minishell->exit = 130;
		ft_dprintf(2, "\n");
	}
}
