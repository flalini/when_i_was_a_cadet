/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 16:39:23 by ijang             #+#    #+#             */
/*   Updated: 2020/11/18 12:44:59 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef R_SPEED
#  define R_SPEED 0.11
# endif

# ifndef M_SPEED
#  define M_SPEED 0.11
# endif

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include "mlx.h"
# include "macro.h"
# include "cub3d_struct.h"
# include "engine.h"
# include "parser.h"
# include "utils.h"
# include "get_next_line.h"

int		check_clear(t_cub3d *cub3d);
int		exit_cub3d(t_cub3d *cub3d);
void	exit_error(int code);
void	init_cub3d(t_cub3d *c);
int		screenshot(t_cub3d *cub3d);
int		main(int argc, char **argv);
int		exit_hook(t_cub3d *cub3d);
int		key_press(int keycode, t_cub3d *cub3d);
int		key_release(int keycode, t_cub3d *cub3d);
int		main_loop(t_cub3d *cub3d);
int		save_bmp(t_cub3d *cub3d);

#endif
