# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ijang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/14 09:46:23 by ijang             #+#    #+#              #
#    Updated: 2021/02/20 17:20:36 by ijang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I includes/

LIBFT = libft/libft.a 

LFLAG = -L libft -lft

HEADER = minishell.h

ENV =		env_utils env_utils2 

PARSING =	token token2 cmds bin_path parsing_token parsing_cmds

COMMANDS =	echo cd exit env pwd unset export

UTILS =		redirect command_process command_process2 free_utils utils utils2 \
			quotes gnl_no_eof exec signals errors ft_dprintf is_numeric_arg

SRC =	srcs/main.c \
		$(addsuffix .c, $(addprefix srcs/env/, $(ENV))) \
		$(addsuffix .c, $(addprefix srcs/parsing/, $(PARSING))) \
		$(addsuffix .c, $(addprefix srcs/commands/, $(COMMANDS))) \
		$(addsuffix .c, $(addprefix srcs/utils/, $(UTILS)))

OBJ = $(SRC:c=o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(LIBFT):
	make bonus -C libft/

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LFLAG)

clean:
	make fclean -C libft/
	rm $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all

norm:
	norminette $(SRC) includes/$(HEADER)

.PHONY: clean fclean re norm
