# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ijang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/11 16:43:08 by ijang             #+#    #+#              #
#    Updated: 2020/11/18 13:11:10 by ijang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			cub3D

CC =			gcc
R_SPEED =		0.11
M_SPEED =		0.11
INCS =			include/
MMS_DIR =		minilibx_mms_20200219/
OPENGL_DIR =	minilibx_opengl_20191021/

LMLX =			libmlx.dylib libmlx.a
LMLX_SRCS =		$(MMS_DIR)libmlx.dylib $(OPENGL_DIR)libmlx.a
LMLXS_DIR =		./
LMLXS =			$(addprefix $(LMLXS_DIR), $(LMLX))
LIBS			= -L$(OPENGL_DIR) -lmlx -framework OpenGL -framework AppKit

CFLAGS =		-Wall -Wextra -Werror -D R_SPEED=$(R_SPEED) -D M_SPEED=$(M_SPEED)

CSRCS_E_LIST =	camera.c				\
				color.c					\
				draw_ceil_floor.c		\
				draw_motion.c			\
				draw_ui.c				\
				draw_wall.c				\
				draw.c					\
				interaction.c			\
				raycast.c				\
				screen.c				\
				sprite_modify.c			\
				sprite_util.c			\
				sprite.c
CSRCS_E_DIR =	engine/
CSRCS_E =		$(addprefix $(CSRCS_E_DIR), $(CSRCS_E_LIST))
CSRCS_G_LIST =	get_next_line_utils.c	\
				get_next_line.c
CSRCS_G_DIR =	gnl/
CSRCS_G =		$(addprefix $(CSRCS_G_DIR), $(CSRCS_G_LIST))
CSRCS_P_LIST =	init_map.c				\
				load_textures_util.c	\
				load_textures.c			\
				make_tables.c			\
				pars_key.c				\
				pars_parameter.c		\
				pars_time.c				\
				parser.c				\
				set_cub3d.c
CSRCS_P_DIR =	parser/
CSRCS_P =		$(addprefix $(CSRCS_P_DIR), $(CSRCS_P_LIST))
CSRCS_U_LIST =	ft_atoi.c				\
				ft_check_ext.c			\
				ft_split.c				\
				ft_strchr.c				\
				ft_strcmp.c				\
				ft_strdup.c				\
				ft_strjoin.c			\
				ft_strlen.c				\
				loca.c					\
				map.c					\
				strlst.c				\
				vect.c
CSRCS_U_DIR =	utils/
CSRCS_U =		$(addprefix $(CSRCS_U_DIR), $(CSRCS_U_LIST))
CSRCS_LIST =	$(CSRCS_E)				\
				$(CSRCS_G)				\
				$(CSRCS_P)				\
				$(CSRCS_U)				\
				cub3d.c					\
				error_code.c			\
				main_loop.c				\
				main.c					\
				screenshot.c
CSRCS_DIR =		common_srcs/
CSRCS =			$(addprefix $(CSRCS_DIR), $(CSRCS_LIST))
COBJS =			$(CSRCS:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCS)

all: $(NAME)

bonus: $(NAME)

$(LMLXS) :
	@make -C $(MMS_DIR) all
	@make -C $(OPENGL_DIR) all
	@cp $(LMLX_SRCS) $(LMLXS_DIR)

$(NAME) : $(COBJS) $(LMLXS)
	@$(CC) $(CFLAGS) $(CSRCS) -I $(INCS) $(LIBS) -o $@

clean :
	@rm -rf $(COBJS)

fclean : clean
	@make -C $(MMS_DIR) clean
	@make -C $(OPENGL_DIR) clean
	@rm -rf $(NAME) $(LMLXS)

re : clean $(NAME)
