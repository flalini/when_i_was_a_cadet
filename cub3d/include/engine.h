/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 17:59:12 by ijang             #+#    #+#             */
/*   Updated: 2020/11/18 12:24:19 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "cub3d_struct.h"

int			move_camera(t_cub3d *cub3d, double direction);
int			move_perp_camera(t_cub3d *cub3d, int direction);
int			rotate_camera(t_cub3d *cub3d, int dir);
int			shade_color(int color, double divide);
int			distance_shade(int options, int color, double distance);
int			get_color(t_tex *tex, t_vect *pos);
void		draw_pixel(t_window *w, t_vect *pos, int color);
int			draw_vertical_line(t_window *win, t_vect *s, int len, int c);
int			draw_rectangle(t_window *win, t_vect *p1, t_vect *p2, int color);
void		draw_ceil_floor(t_cub3d *cub3d, t_calray *ray);
void		draw_motion(t_cub3d *cub3d);
void		update_ui(t_cub3d *cub3d);
void		draw_wall(t_cub3d *c, t_calray *r);
int			interaction(t_cub3d *cub3d);
int			wall_direction(t_calray *ray);
void		init_ray(t_calray *r, t_camera *c, int x, double camera_x);
double		ray_distance(t_cub3d *cub3d, t_calray *r);
void		ray_cast(t_cub3d *cub3d, t_calray *ray, int x);
void		update_window(t_cub3d *cub3d);
void		update_screen(t_cub3d *cub3d);
void		modify_sprite(t_sprite **sprites, t_vect *pos, t_vect *next);
void		draw_sprites(t_cub3d *cub);
int			add_front_sprite(t_sprite **start, t_vect *pos, int count,
	t_tex *tex);
t_sprite	*add_sorted_sprite(t_sprite **sorted, t_sprite *sprite);
t_sprite	*sort_sprites(t_cub3d *cub3d, t_sprite *sprites);
void		delete_sprite(t_sprite **sprites, t_vect *pos);
void		clear_sprites(t_sprite **sprites);

#endif
