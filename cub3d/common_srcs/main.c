/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 16:43:15 by ijang             #+#    #+#             */
/*   Updated: 2021/03/01 18:04:57 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_cub3d(t_cub3d *c)
{
	int		i;

	set_vect(&c->move, 0.0, 0.0);
	set_vect(&c->x_move, 0.0, 0.0);
	set_vect(&c->rotate, 0.0, 0.0);
	c->space = 0;
	c->dash = 1.0;
	c->frame = -1;
	c->option = 0x00000011;
	c->fov = 0.66;
	c->sprite = NULL;
	i = -1;
	while (++i < TEXTURES_NUM)
		c->tex[i].tex = NULL;
	i = -1;
	while (++i < ANIMATION_NUM)
	{
		c->ani[i].count = 0;
		c->ani[i].tex = NULL;
	}
	c->exit = 0;
	c->clear = 0;
}

int		screenshot(t_cub3d *cub3d)
{
	++(cub3d->frame);
	update_screen(cub3d);
	update_ui(cub3d);
	update_window(cub3d);
	if (!save_bmp(cub3d))
	{
		clear_animations(cub3d);
		clear_sprites(&cub3d->sprite);
		clear_window(&cub3d->window);
		exit_error(14);
	}
	clear_animations(cub3d);
	clear_sprites(&cub3d->sprite);
	clear_window(&cub3d->window);
	exit(EXIT_SUCCESS);
	return (0);
}

int		main(int argc, char **argv)
{
	t_cub3d	cub3d;
	int		save;
	int		error_code;

	errno = 0;
	save = (argc == 3 && !ft_strcmp(argv[2], "--save"));
	if (argc != (2 + save))
		exit_error(0);
	init_cub3d(&cub3d);
	if ((error_code = parser(&cub3d, argv[1])))
	{
		clear_animations(&cub3d);
		clear_sprites(&cub3d.sprite);
		clear_window(&cub3d.window);
		exit_error(error_code);
	}
	if (save)
		return (screenshot(&cub3d));
	mlx_hook(cub3d.window.win, X_EVENT_KEY_PRESS, 0, &key_press, &cub3d);
	mlx_hook(cub3d.window.win, X_EVENT_KEY_RELEASE, 0, &key_release, &cub3d);
	mlx_hook(cub3d.window.win, X_EVENT_EXIT, 0, &exit_hook, &cub3d);
	mlx_loop_hook(cub3d.window.mlx, &main_loop, &cub3d);
	mlx_loop(cub3d.window.mlx);
	return (EXIT_SUCCESS);
}
