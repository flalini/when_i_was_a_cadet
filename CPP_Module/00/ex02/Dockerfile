# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ijang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/29 18:40:31 by ijang             #+#    #+#              #
#    Updated: 2021/03/29 19:08:21 by ijang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM		ubuntu:latest

RUN			apt-get update
RUN			apt-get -y upgrade
RUN			apt-get -y install clang

COPY		Account.class.cpp ./
COPY		test/* ./

ENTRYPOINT	["sh", "test.sh"]
