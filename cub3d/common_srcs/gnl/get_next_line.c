/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:41:48 by ijang             #+#    #+#             */
/*   Updated: 2020/10/30 20:45:08 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_gnllst	*ft_newgnllst(int fd)
{
	t_gnllst	*new;

	if (!(new = (t_gnllst *)malloc(sizeof(t_gnllst))))
		return (0);
	if (!(new->buffer = (char *)malloc(BUFFER_SIZE + 1)))
	{
		free(new);
		return (0);
	}
	new->fd = fd;
	new->backup = 0;
	new->next = 0;
	return (new);
}

int			ft_dellst(t_gnllst *lst, t_gnllst **start)
{
	t_gnllst		*tmp;

	if (*start == lst)
		*start = lst->next;
	else
	{
		tmp = *start;
		while (tmp->next != lst)
			tmp = tmp->next;
		tmp->next = lst->next;
	}
	if (lst->backup)
		free(lst->backup);
	free(lst->buffer);
	free(lst);
	return (-1);
}

int			ft_makeline(t_gnllst *lst, char *buffer, t_gnllst **start, \
		char **line)
{
	char	*p;
	char	*tmp;

	if ((p = ft_strchr(buffer, '\n')))
	{
		*p = '\0';
		if (!(*line = ft_strdup(buffer)))
		{
			*p = '\n';
			return (-1);
		}
		tmp = buffer;
		if (!(buffer = ft_strdup(p + 1)))
		{
			*p = '\n';
			return (-1);
		}
		free(tmp);
		lst->backup = buffer;
		return (1);
	}
	if (!(*line = ft_strdup(buffer)))
		return (-1);
	ft_dellst(lst, start);
	return (0);
}

int			ft_subgnl(t_gnllst *lst, char **line, t_gnllst **start)
{
	ssize_t	len_read;
	char	*tmp;

	while ((len_read = read(lst->fd, lst->buffer, BUFFER_SIZE)) > 0)
	{
		if (!(tmp = (char *)malloc((lst->backup ? ft_strlen(lst->backup) : 0) \
					+ (size_t)len_read + 1)))
			return (-1);
		(lst->buffer)[len_read] = 0;
		ft_strgnlcpy(ft_strgnlcpy(tmp, lst->backup), lst->buffer);
		if (lst->backup)
			free(lst->backup);
		lst->backup = tmp;
		if (ft_strchr(lst->backup, '\n'))
			break ;
	}
	if (len_read == -1)
		return (ft_dellst(lst, start));
	if (!len_read && !lst->backup)
		if (!(lst->backup = ft_strdup("")))
			return (-1);
	return (ft_makeline(lst, lst->backup, start, line));
}

int			get_next_line(int fd, char **line)
{
	static t_gnllst	*gnllst;
	t_gnllst		*lst;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (!gnllst)
	{
		if (!(gnllst = ft_newgnllst(fd)))
			return (-1);
		lst = gnllst;
		return (ft_subgnl(lst, line, &gnllst));
	}
	lst = gnllst;
	while (lst->fd != fd && lst->next != 0)
		lst = lst->next;
	if (lst->fd != fd)
	{
		if (!(lst->next = ft_newgnllst(fd)))
			return (-1);
		lst = lst->next;
	}
	if (lst->backup && ft_strchr(lst->backup, '\n'))
		return (ft_makeline(lst, lst->backup, &gnllst, line));
	return (ft_subgnl(lst, line, &gnllst));
}
