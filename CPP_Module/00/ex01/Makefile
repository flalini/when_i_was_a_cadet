# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ijang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/23 20:15:26 by ijang             #+#    #+#              #
#    Updated: 2021/02/25 15:29:45 by ijang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		LTQ_PhoneBook

CXX =		clang++

CXXFLAGS =	-Wall -Wextra -Werror

CLASSES =	LTQ_PhoneBook PhoneBook_Info

SRCS =		main.cpp						\
			$(addsuffix .cpp, $(CLASSES))

OBJS =		$(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ -I .

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS) -I .

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
