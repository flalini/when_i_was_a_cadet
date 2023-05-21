/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 10:35:18 by ijang             #+#    #+#             */
/*   Updated: 2021/02/16 11:13:32 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_strlen_s(char *s)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != ' ')
			count++;
		i++;
	}
	return (count);
}

void	echo_cmd(t_minishell *minishell, t_cmd *cmd)
{
	t_token		*args;
	int			endl;

	args = cmd->args;
	endl = 1;
	while (args && ft_strequ(args->word, "-n"))
	{
		endl = 0;
		args = args->next;
	}
	while (args)
	{
		ft_putstr(args->word);
		if (args->next)
			ft_putchar(' ');
		args = args->next;
	}
	if (endl)
		ft_putchar('\n');
	minishell->exit = 0;
}
