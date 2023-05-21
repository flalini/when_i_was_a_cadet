# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ijang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/04 23:15:22 by ijang             #+#    #+#              #
#    Updated: 2020/12/22 22:06:02 by ijang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =				libasm.a

NASM =				nasm
NFLAGS =			-f macho64

AR =				ar rc

CC =				gcc
CFLAGS =			-Wall -Wextra -Werror

SRCS =				ft_read.s					\
					ft_strcmp.s					\
					ft_strcpy.s					\
					ft_strdup.s					\
					ft_strlen.s					\
					ft_write.s
OBJS =				$(SRCS:.s=.o)

BONUS_SRCS =		ft_atoi_base.s				\
					ft_list_push_front.s		\
					ft_list_size.s				\
					ft_list_sort.s				\
					ft_list_remove_if.s
BONUS_OBJS =		$(BONUS_SRCS:.s=.o)

TEST_SRCS_LIST =	main.c						\
					ft_strlen_test.c			\
					ft_strcpy_test.c			\
					ft_strcmp_test.c			\
					ft_write_test.c				\
					ft_read_test.c				\
					ft_strdup_test.c			\
					ft_atoi_base_test.c			\
					ft_list_util.c				\
					ft_list_util2.c				\
					ft_list_push_front_test.c	\
					ft_list_size_test.c			\
					ft_list_sort_test.c			\
					ft_list_remove_if_test.c
TEST_DIR =			test/
TEST_SRCS =			$(addprefix $(TEST_DIR), $(TEST_SRCS_LIST))
TEST_OBJS =			$(TEST_SRCS:.c=.o)


%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(TEST_DIR)

%.o: %.s
	@$(NASM) $(NFLAGS) $< -o $(<:.s=.o)

all: $(NAME)

bonus: $(OBJS) $(BONUS_OBJS)
	@$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)

test: bonus $(TEST_OBJS)
	@$(CC) $(CFLAGS) -o test.out $(TEST_OBJS) -I $(TEST_DIR) -L./ -lasm

$(NAME) : $(OBJS)
	@$(AR) $(NAME) $(OBJS)

clean :
	@rm -rf $(OBJS) $(BONUS_OBJS) $(TEST_OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean $(NAME)
