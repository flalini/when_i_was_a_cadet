/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:40:33 by ijang             #+#    #+#             */
/*   Updated: 2020/11/18 12:12:44 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	error_write2(int code)
{
	char	*text;

	if (code == 7)
		text = "Malloc error!\nIn strlst_add_back\n";
	else if (code == 8)
		text = "GNL error? Wait...... Seriously?\n";
	else if (code == 9)
		text = "Malloc failed!\n";
	else if (code == 10)
		text = "mlx failed to create window\n";
	else if (code == 11)
		text = "Failed to load texture(s).\n";
	else if (code == 12)
		text = "Failed to load texture(s) or malloc texture(s).\n";
	else if (code == 13)
		text = "Failed to malloc sprites.\n";
	else if (code == 14)
		text = "Failed to save screenshot.\n";
	else
		return ;
	write(2, text, ft_strlen(text));
}

static void	error_write(int code)
{
	char	*text;

	if (code == 0)
		text = "Argument error!\n";
	else if (code == 1)
		text = "Extension error!\n";
	else if (code == 2)
		text = "Failed to open file\n";
	else if (code == 3)
		text = "This map is too big.\n";
	else if (code == 4)
		text = "Map invaild!\n";
	else if (code == 5)
		text = "Split error!\nI knew this would happen.\n";
	else if (code == 6)
		text = "This code was coded by an idiot.\nstrlst_add_back NULL\n";
	else
	{
		error_write2(code);
		return ;
	}
	write(2, text, ft_strlen(text));
}

void		exit_error(int code)
{
	char	*error_text;

	error_text = NULL;
	write(2, "Error\n", 6);
	if (code)
		error_write(code);
	if (errno)
	{
		if ((error_text = strerror(errno)))
		{
			write(2, error_text, ft_strlen(error_text));
			write(2, "\n", 1);
		}
	}
	exit(EXIT_FAILURE);
}
