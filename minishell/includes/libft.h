/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 14:44:53 by ijang             #+#    #+#             */
/*   Updated: 2021/02/18 02:00:34 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <errno.h>

int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t len);
char			*ft_strnstr(const char *big, const char *little, size_t len);
int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t len);
void			*ft_memset(void *s, int c, size_t len);
void			*ft_memccpy(void *dst, const void *src, int c, size_t len);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *b, int c, size_t len);
int				ft_memcmp(const void *b1, const void *b2, size_t len);
void			*ft_calloc(size_t number, size_t size);
char			*ft_strdup(const char *src);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
		void (*del)(void *));

int				ft_count_split(char **split);
void			ft_free_split(char ***split);
void			ft_putchar(char c);
void			ft_putendl(char *s);
void			ft_putnbr(int n);
void			ft_putstr(char *s);
char			**ft_split_n(char const *s, char c, int n);
char			**ft_ssplit(char const *s, char *set);
int				ft_str_end(char *str, char *end);
char			*ft_strcat(char *dst, const char *src);
char			*ft_strndup(const char *src, int n);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dst, const char *src);
int				ft_strequ(const char *s1, const char *s2);
void			ft_strdel(char **as);
char			*ft_strjoin_free(char const *s1, char const *s2);
char			*ft_strjoin_double_free(char const *s1, char const *s2);
size_t			ft_strlen_c(char *s, char c);
int				ft_is_in_stri(char c, char *str);

void			ft_lst_remove_if(t_list **begin_list, void *data_ref,
		int (*cmp)(), void (*del)());

#endif
