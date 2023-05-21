/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cub3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 12:13:39 by ijang             #+#    #+#             */
/*   Updated: 2020/11/18 11:53:30 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			clear_window(t_window *window)
{
	if (window->mlx)
	{
		if (window->win)
		{
			if (window->screen.ptr)
			{
				mlx_destroy_image(window->mlx, window->screen.ptr);
				window->screen.ptr = NULL;
			}
			mlx_destroy_window(window->mlx, window->win);
			window->win = NULL;
		}
		free(window->mlx);
		window->mlx = NULL;
	}
	return (0);
}

static int	find_sprites(t_cub3d *cu)
{
	int		i;
	int		j;
	int		c;
	t_tex	*tex;
	t_vect	pos;

	i = -1;
	while (++i < cu->map_size.y)
	{
		j = -1;
		while (++j < cu->map_size.x)
		{
			c = cu->map[i * cu->map_size.x + j];
			if (c >= '2' && c <= '5')
			{
				set_vect(&pos, (double)j + 0.5, (double)i + 0.5);
				tex = (c == '2') ? &cu->tex[TEX_SPRITE] : cu->ani[c - '3'].tex;
				c = (c == '2') ? 1 : cu->ani[c - '3'].count;
				if (tex && tex->tex &&
					!add_front_sprite(&cu->sprite, &pos, c, tex))
					return (0);
			}
		}
	}
	return (1);
}

static int	init_window(t_window *window, t_loca r_size, double *fov)
{
	set_loca(&(window->size), (r_size.x > 1600) ? 1600 : r_size.x,
		(r_size.y > 776) ? 776 : r_size.y);
	if (window->size.x < 848)
		window->size.x = 848;
	if (window->size.y < 480)
		window->size.y = 480;
	window->ratio = ((double)window->size.x) / ((double)window->size.y);
	if (window->ratio < BEST_RATIO)
		*fov = *fov / ((BEST_RATIO / *fov) / 2.5);
	else if (window->ratio > BEST_RATIO)
		*fov = *fov * ((*fov / BEST_RATIO) * 2.5);
	if (!(window->mlx = mlx_init()))
		return (0);
	if (!(window->win =
		mlx_new_window(window->mlx, window->size.x, window->size.y, "cub3d")))
		return (0);
	set_vect(&window->half,
		(double)window->size.x / 2.0, (double)window->size.y / 2.0);
	if (!(window->screen.ptr =
		mlx_new_image(window->mlx, window->size.x, window->size.y)))
		return (clear_window(window));
	window->screen.data = (int *)mlx_get_data_addr(window->screen.ptr,
		&window->screen.bpp, &window->screen.size_l, &window->screen.endian);
	return (1);
}

static void	find_start(t_cub3d *cub3d, t_camera *camera, int *map)
{
	int		i;

	i = 0;
	while (!ft_strchr("NSEW", map[i]))
		++i;
	set_vect(&camera->pos,
		(double)(i % cub3d->map_size.x) + 0.5,
		(double)(i / cub3d->map_size.x) + 0.5);
	if (map[i] == 'N')
		set_vect(&camera->dir, 0.0, -1.0);
	else if (map[i] == 'E')
		set_vect(&camera->dir, 1.0, 0.0);
	else if (map[i] == 'S')
		set_vect(&camera->dir, 0.0, 1.0);
	else
		set_vect(&camera->dir, -1.0, 0.0);
	set_vect(&camera->plane,
		cub3d->fov * -camera->dir.y, cub3d->fov * camera->dir.x);
	set_vect(&camera->x_dir, camera->dir.y, -camera->dir.x);
	map[i] = '0';
}

int			set_cub3d(t_cub3d *cub3d, t_pars *pars)
{
	int		i;

	i = -1;
	while (++i < TEXTURES_NUM)
		cub3d->color[i] = pars->color[i];
	cub3d->time = (double)pars->time;
	if (!init_window(&(cub3d->window), pars->r_size, &(cub3d->fov)))
		return (10);
	find_start(cub3d, &cub3d->camera, cub3d->map);
	if (!load_textures(cub3d, pars))
		return (11);
	if (!load_animations(cub3d, pars))
		return (12);
	if (!find_sprites(cub3d))
	{
		clear_sprites(&cub3d->sprite);
		clear_animations(cub3d);
		return (13);
	}
	make_tables(cub3d);
	return (0);
}
