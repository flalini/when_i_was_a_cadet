/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 17:28:45 by ijang             #+#    #+#             */
/*   Updated: 2020/12/22 21:49:41 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <ctype.h>
# include <limits.h>

extern char			*g_strings[];

/*
** mandatory
*/
int					ft_strlen(char *str);
char				*ft_strcpy(char *dst, const char *src);
int					ft_strcmp(const char *s1, const char *s2);
ssize_t				ft_write(int fildes, const void *buf, size_t buf_size);
ssize_t				ft_read(int fildes, void *buf, size_t buf_size);
char				*ft_strdup(const char *str);

/*
** bonus
*/
int					ft_atoi_base(const char *str, const char *base);

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

void				ft_list_push_front(t_list **begin_list, void *data);
int					ft_list_size(t_list *begin_list);
void				ft_list_sort(t_list **begin_list, int (*cmp)());
void				ft_list_remove_if(t_list **begin_list, void *data_ref,
							int (*cmp)(), void (*free_fct)(void *));

/*
** test_functions
*/
void				ft_strlen_test(void);
void				ft_strcpy_test(void);
void				ft_strcmp_test(void);
void				ft_write_test(void);
void				ft_read_test(void);
void				ft_strdup_test(void);

void				ft_atoi_base_test(void);
void				ft_list_push_front_test(void);
void				ft_list_size_test(void);
void				ft_list_sort_test(void);
void				ft_list_remove_if_test(void);

t_list				*list_from_format(char *format);
t_list				*ft_list_clear(t_list *list);
void				ft_list_malloc_fail(t_list *l1, t_list *l2, t_list *l3);
int					list_cmp(t_list *l1, t_list *l2);
void				list_print(t_list *list);
void				print_list_result(t_list *from,
							t_list *expected, t_list *actual);
int					ft_data_cmp(void *d1, void *d2);

#endif
