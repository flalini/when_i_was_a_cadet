# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ijang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/01 15:57:34 by ijang             #+#    #+#              #
#    Updated: 2021/02/18 02:13:20 by ijang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PATH_SRCS =		./

SRCS =			${PATH_SRCS}ft_atoi.c					\
				${PATH_SRCS}ft_isalpha.c				\
				${PATH_SRCS}ft_memccpy.c				\
				${PATH_SRCS}ft_memmove.c				\
				${PATH_SRCS}ft_strlcat.c				\
				${PATH_SRCS}ft_strnstr.c				\
				${PATH_SRCS}ft_bzero.c					\
				${PATH_SRCS}ft_isascii.c				\
				${PATH_SRCS}ft_memchr.c					\
				${PATH_SRCS}ft_memset.c					\
				${PATH_SRCS}ft_strlcpy.c				\
				${PATH_SRCS}ft_strrchr.c				\
				${PATH_SRCS}ft_calloc.c					\
				${PATH_SRCS}ft_isdigit.c				\
				${PATH_SRCS}ft_memcmp.c					\
				${PATH_SRCS}ft_strchr.c					\
				${PATH_SRCS}ft_strlen.c					\
				${PATH_SRCS}ft_tolower.c				\
				${PATH_SRCS}ft_isalnum.c				\
				${PATH_SRCS}ft_isprint.c				\
				${PATH_SRCS}ft_memcpy.c					\
				${PATH_SRCS}ft_strdup.c					\
				${PATH_SRCS}ft_strncmp.c				\
				${PATH_SRCS}ft_toupper.c				\
				${PATH_SRCS}ft_itoa.c					\
				${PATH_SRCS}ft_putendl_fd.c				\
				${PATH_SRCS}ft_putstr_fd.c				\
				${PATH_SRCS}ft_strjoin.c				\
				${PATH_SRCS}ft_strtrim.c				\
				${PATH_SRCS}ft_putchar_fd.c				\
				${PATH_SRCS}ft_putnbr_fd.c				\
				${PATH_SRCS}ft_split.c					\
				${PATH_SRCS}ft_strmapi.c				\
				${PATH_SRCS}ft_substr.c					\
				${PATH_SRCS}ft_count_split.c			\
				${PATH_SRCS}ft_free_split.c				\
				${PATH_SRCS}ft_is_in_stri.c				\
				${PATH_SRCS}ft_putchar.c				\
				${PATH_SRCS}ft_putendl.c				\
				${PATH_SRCS}ft_putnbr.c					\
				${PATH_SRCS}ft_putstr.c					\
				${PATH_SRCS}ft_split_n.c				\
				${PATH_SRCS}ft_ssplit.c					\
				${PATH_SRCS}ft_str_end.c				\
				${PATH_SRCS}ft_strcat.c					\
				${PATH_SRCS}ft_strcmp.c					\
				${PATH_SRCS}ft_strcpy.c					\
				${PATH_SRCS}ft_strdel.c					\
				${PATH_SRCS}ft_strequ.c					\
				${PATH_SRCS}ft_strjoin_free.c			\
				${PATH_SRCS}ft_strjoin_double_free.c	\
				${PATH_SRCS}ft_strlen_c.c				\
				${PATH_SRCS}ft_strndup.c

SRCS_BONUS =	${PATH_SRCS}ft_lstadd_back_bonus.c	\
				${PATH_SRCS}ft_lstdelone_bonus.c	\
				${PATH_SRCS}ft_lstmap_bonus.c		\
				${PATH_SRCS}ft_lstadd_front_bonus.c	\
				${PATH_SRCS}ft_lstiter_bonus.c		\
				${PATH_SRCS}ft_lstnew_bonus.c		\
				${PATH_SRCS}ft_lstclear_bonus.c		\
				${PATH_SRCS}ft_lstlast_bonus.c		\
				${PATH_SRCS}ft_lstsize_bonus.c		\
				${PATH_SRCS}ft_lst_remove_if.c

OBJS =			${SRCS:.c=.o}

OBJS_BONUS =	${SRCS_BONUS:.c=.o}

INCS =			./

NAME =			libft.a

AR =			ar rc

CC =			gcc

RM =			rm -f

CFLAGS =		-Wall -Wextra -Werror

%.o: %.c
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${INCS}
	
${NAME} : ${OBJS}
	${AR} ${NAME} ${OBJS}
	ranlib $@

bonus : ${OBJS} ${OBJS_BONUS}
	${AR} ${NAME} ${OBJS} ${OBJS_BONUS}

all : ${NAME}

clean :
	${RM} ${OBJS} ${OBJS_BONUS}

fclean : clean
	${RM} ${NAME}

re : fclean all
