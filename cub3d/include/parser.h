/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:07:07 by ijang             #+#    #+#             */
/*   Updated: 2020/11/18 12:21:41 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "cub3d_struct.h"

int		map_parsing(t_cub3d *cub3d, t_strlst *buffer);
void	find_texture_empty(t_tex *tex);
int		clear_textures(t_cub3d *cub3d);
int		clear_animations(t_cub3d *cub3d);
int		load_animations(t_cub3d *c, t_pars *p);
int		load_textures(t_cub3d *c, t_pars *p);
void	make_tables(t_cub3d *cub3d);
int		pars_key(char *l);
int		pars_resolution(t_pars *pars);
int		pars_color(t_pars *pars, int tex_num);
int		pars_texture(t_pars *pars, int key);
int		pars_ani(t_pars *pars, int key);
int		pars_time(t_pars *pars);
int		parser(t_cub3d *cub3d, char *map_path);
int		clear_window(t_window *window);
int		set_cub3d(t_cub3d *cub3d, t_pars *pars);

#endif
