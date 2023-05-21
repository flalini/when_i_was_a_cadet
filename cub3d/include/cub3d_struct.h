/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 18:00:27 by ijang             #+#    #+#             */
/*   Updated: 2020/11/18 12:22:17 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

# include "macro.h"

typedef struct	s_vect
{
	double			x;
	double			y;
}				t_vect;

typedef struct	s_loca
{
	int				x;
	int				y;
}				t_loca;

typedef struct	s_img
{
	void			*ptr;
	int				*data;
	t_loca			size;

	int				size_l;
	int				bpp;
	int				endian;
}				t_img;

typedef struct	s_tex
{
	void			*tex;
	int				*data;
	t_loca			size;
	t_loca			start;
	t_loca			end;

	int				size_l;
	int				bpp;
	int				endian;
}				t_tex;

typedef struct	s_ani
{
	t_tex			*tex;
	int				count;
}				t_ani;

typedef struct	s_sprite_draw
{
	int			sprite_screen;
	t_vect		pos;
	t_vect		transform;
	t_vect		spr_s;
	t_vect		draw_x;
	t_vect		draw_y;
	t_vect		tex_pos;
	int			fact;
	int			draw_y_org;
}				t_sprite_draw;

typedef struct	s_sprite
{
	t_vect			pos;
	double			distance;
	t_tex			*ani;
	int				count;
	struct s_sprite	*next;
	struct s_sprite	*sorted;
}				t_sprite;

typedef struct	s_window
{
	void			*mlx;
	void			*win;
	t_img			screen;
	t_loca			size;
	t_vect			half;
	double			ratio;
}				t_window;

typedef struct	s_camera
{
	t_vect			pos;
	t_vect			dir;
	t_vect			x_dir;
	t_vect			plane;
}				t_camera;

typedef struct	s_calray
{
	t_loca			loca;
	double			distance;
	int				direction;
	int				side;
	int				height;
	t_vect			ray_pos;
	t_vect			ray_dir;
	t_vect			map_pos;
	t_vect			side_dist;
	t_vect			delta_dist;
	t_vect			step;
	double			wall_x;
	t_vect			floor_wall;
	t_vect			c_floor;
}				t_calray;

typedef struct	s_motion
{
	t_vect			pos;
	t_vect			start;
	t_vect			end;
	t_vect			size;
	t_vect			cal;
	t_tex			*t;
}				t_motion;

typedef struct	s_strlst
{
	char			*text;
	struct s_strlst	*next;
}				t_strlst;

typedef struct	s_pars
{
	int				m_fd;
	int				map_end;
	t_loca			r_size;
	int				set[PARS_NUM];
	char			*tex_path[TEXTURES_NUM];
	char			**ani_path[TEXTURES_NUM];
	unsigned int	color[TEXTURES_NUM];
	char			*line;
	t_strlst		*buffer;
	int				time;
}				t_pars;

typedef struct	s_cub3d
{
	t_window		window;
	t_camera		camera;
	t_sprite		*sprite;
	unsigned int	color[TEXTURES_NUM];
	t_tex			tex[TEXTURES_NUM];
	t_ani			ani[ANIMATION_NUM];
	t_vect			move;
	t_vect			x_move;
	t_vect			rotate;
	int				frame;
	double			dash;
	int				space;
	int				option;
	double			time;
	int				*map;
	t_loca			map_size;
	int				exit;
	int				clear;
	double			fov;
	double			camera_x[1920];
	double			depth[1920];
	double			sf_dist[1080];
	double			cos[2];
	double			sin[2];
}				t_cub3d;

#endif
