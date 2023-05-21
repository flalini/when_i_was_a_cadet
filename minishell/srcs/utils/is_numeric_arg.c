/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_numeric_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 17:01:33 by ijang             #+#    #+#             */
/*   Updated: 2021/02/20 17:16:25 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_numeric_arg(char *word)
{
	if (*word == '-')
	{
		++word;
		if (!is_only_digit(word) || ft_strlen(word) > 19
			|| (ft_strlen(word) == 19
			&& ft_strcmp(word, "9223372036854775808") > 0))
			return (0);
	}
	else if (!is_only_digit(word) || ft_strlen(word) > 19
		|| (ft_strlen(word) == 19
		&& ft_strcmp(word, "9223372036854775807") > 0))
		return (0);
	return (1);
}
