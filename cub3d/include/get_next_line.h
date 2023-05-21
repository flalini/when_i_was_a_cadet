/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:41:16 by ijang             #+#    #+#             */
/*   Updated: 2020/11/18 12:25:38 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef struct	s_gnllst
{
	int				fd;
	char			*backup;
	char			*buffer;
	struct s_gnllst	*next;
}				t_gnllst;

t_gnllst		*ft_newgnllst(int fd);
int				ft_dellst(t_gnllst *lst, t_gnllst **start);
int				ft_makeline(t_gnllst *lst, char *buffer, t_gnllst **start,
	char **line);
int				ft_subgnl(t_gnllst *lst, char **line, t_gnllst **start);
int				get_next_line(int fd, char **line);
char			*ft_strgnlcpy(char *dst, char *src);

#endif
