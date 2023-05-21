/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 18:57:57 by ijang             #+#    #+#             */
/*   Updated: 2021/02/16 21:01:06 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*replace_env(char *str, int i)
{
	int		k;
	int		j;
	char	*tmp;
	char	*new;

	k = ft_quotelen(str, 4, 1);
	if (!(new = (char *)ft_calloc(1, k + 1)))
		exit(1);
	j = 0;
	while (str[i] && j < k)
	{
		if (str[i] == '$' && !is_escaped(str, i - 1))
		{
			tmp = replace_env2(str, &i);
			j = ft_strlcat(new, tmp, k);
			free(tmp);
			continue ;
		}
		if ((str[i] != '\\' || is_escaped(str, i - 1)) && j < k)
			new[j++] = str[i];
		i++;
	}
	free(str);
	return (new);
}

char	*replace_env2(char *str, int *i)
{
	int		count;
	char	buf[4096];
	char	*new;

	new = ft_strdup("");
	count = 0;
	(*i)++;
	ft_bzero(buf, sizeof(buf));
	while (str[*i] && (ft_isalnum(str[*i]) || is_char_str(str[*i], "?_")))
	{
		buf[count] = str[*i];
		*i = *i + 1;
		if (str[*i - 1] == '?' && count == 0)
			break ;
		if (ft_isdigit(str[*i - 1]) && count == 0)
			return (new);
		count++;
	}
	new = ft_strjoin_free(new, get_env(g_minishell, buf));
	return (new);
}

int		in_bracket(char *s, int pos)
{
	int	bracket1;
	int	bracket2;
	int	i;

	bracket1 = 0;
	bracket2 = 0;
	i = -1;
	while (++i <= pos)
	{
		if (s[i] == 34 && (i == 0 || !is_escaped(s, i - 1))
			&& bracket2 % 2 == 0)
			bracket1++;
		if (s[i] == 39 && (i == 0 || bracket2 % 2 != 0 || !is_escaped(s, i - 1))
			&& bracket1 % 2 == 0)
			bracket2++;
	}
	if (bracket1 % 2 != 0 || bracket2 % 2 != 0)
		return (1);
	return (0);
}

int		is_only_digit(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}

int		is_char_str(char c, char *str)
{
	if (ft_is_in_stri(c, str) >= 0)
		return (1);
	return (0);
}
