/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:13:04 by ijang             #+#    #+#             */
/*   Updated: 2020/11/18 13:10:03 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include "cub3d_struct.h"

int		ft_atoi(const char *str);
int		ft_check_ext(char *s1, char *s2);
char	**ft_split(char const *s, char c);
void	clear_split(char **strs, int save_line);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
void	set_loca(t_loca *loca, int x, int y);
void	copy_loca(t_loca *loca, t_loca *org);
int		in_map(t_vect *pos, t_cub3d *cub3d);
int		map(t_vect *pos, t_cub3d *cub3d);
int		map_xy(double x, double y, t_cub3d *cub3d);
int		map_ixy(int	x, int y, t_cub3d *cub3d);
double	max(double x, double y);
int		strlst_add_back(t_strlst **start, char *text);
void	set_vect(t_vect *vect, double x, double y);
void	copy_vect(t_vect *vect, t_vect *org);

#endif
