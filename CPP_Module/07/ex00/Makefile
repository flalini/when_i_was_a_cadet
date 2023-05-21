# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ijang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/23 19:22:08 by ijang             #+#    #+#              #
#    Updated: 2021/04/19 14:55:51 by ijang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		whatever

CXX =		clang++

CXXFLAGS =	-Wall -Wextra -Werror -std=c++98

SRC =		main.cpp
OBJ =		$(SRC:cpp=o)

all: $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ -I .

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
