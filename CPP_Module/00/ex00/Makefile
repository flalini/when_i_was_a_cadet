# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ijang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/23 19:22:08 by ijang             #+#    #+#              #
#    Updated: 2021/02/23 19:45:59 by ijang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		megaphone

CXX =		clang++

CXXFLAGS =	-Wall -Wextra -Werror

SRC =		$(NAME).cpp
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

.PHONY: clean fclean re
