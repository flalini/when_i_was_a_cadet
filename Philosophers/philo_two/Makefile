# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ijang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/27 12:07:57 by ijang             #+#    #+#              #
#    Updated: 2021/03/09 19:36:00 by ijang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		philo_two

CC =		gcc

CFLAGS =	-Wall -Wextra -Werror -pthread -I includes/

HEADER =	philo_two.h

FILES =		init monitor put routine thread time utils sem_utils

SRCS =		main.c \
			$(addsuffix .c, $(FILES))

OBJS =		$(SRCS:c=o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

norm:
	norminette $(SRCS) $(HEADER)

.PHONY: clean fclean re norm
