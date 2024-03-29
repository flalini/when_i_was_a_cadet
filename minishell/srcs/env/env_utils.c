/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 13:52:43 by ijang             #+#    #+#             */
/*   Updated: 2021/02/14 16:36:57 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_env(t_minishell *minishell, char *env, char *value)
{
	t_list	*tmp;
	char	*to_free;
	t_env	*tmp2;

	tmp = minishell->env_list;
	while (tmp)
	{
		tmp2 = tmp->content;
		if (ft_strequ(env, tmp2->name))
		{
			to_free = tmp2->value;
			tmp2->value = ft_strdup(value);
			free(to_free);
			return ;
		}
		tmp = tmp->next;
	}
}

t_env	*create_env(char **split, int ex)
{
	t_env	*env;

	if (!(env = ft_calloc(1, sizeof(t_env))))
		exit_cmd(g_minishell);
	env->name = ft_strdup(split[0]);
	if (split[1])
		env->value = ft_strndup(split[1], 4096);
	else if (ex)
		env->value = NULL;
	else
		env->value = ft_strdup("");
	env->tmp = 0;
	return (env);
}

void	env_init(t_minishell *minishell, char **env)
{
	int		i;
	char	**tmp_split;
	t_env	*tmp;

	i = 0;
	while (env[i])
	{
		tmp_split = ft_split(env[i], '=');
		if (!(tmp = create_env(tmp_split, 0)))
		{
			ft_free_split(&tmp_split);
			return ;
		}
		ft_lstadd_back(&minishell->env_list, ft_lstnew(tmp));
		ft_free_split(&tmp_split);
		i++;
	}
	minishell->env_array = env_to_array(minishell);
	if (get_env(minishell, "PATH"))
		parse_bin(minishell);
}

char	**env_to_array(t_minishell *minishell)
{
	int		i;
	t_list	*tmp;
	char	**array;

	if (!(array = ft_calloc(1, sizeof(char*) * (ft_lstsize(minishell->env_list)
		+ 1))))
		exit_cmd(minishell);
	i = 0;
	tmp = minishell->env_list;
	while (tmp)
	{
		array[i] = ft_strjoin(((t_env*)(tmp->content))->name, "=");
		array[i] = ft_strjoin_free(array[i], ((t_env*)(tmp->content))->value);
		i++;
		tmp = tmp->next;
	}
	array[i] = NULL;
	if (minishell->env_array)
		ft_free_split(&minishell->env_array);
	return (array);
}

char	*get_env(t_minishell *minishell, char *env)
{
	t_list	*tmp;

	tmp = minishell->env_list;
	while (tmp)
	{
		if (ft_strequ(env, ((t_env*)(tmp->content))->name))
			return (((t_env*)(tmp->content))->value);
		tmp = tmp->next;
	}
	if (ft_strequ(env, "?"))
	{
		ft_strdel(&minishell->exit_str);
		minishell->exit_str = ft_itoa(minishell->exit);
		return (minishell->exit_str);
	}
	return (NULL);
}
