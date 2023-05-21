/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 22:42:22 by ijang             #+#    #+#             */
/*   Updated: 2020/11/18 12:04:49 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		exit_hook(t_cub3d *cub3d)
{
	exit_cub3d(cub3d);
	return (0);
}

int		key_press(int keycode, t_cub3d *cub3d)
{
	if (keycode == KEY_W || keycode == KEY_FORWARD)
		cub3d->move.x = 1.0;
	else if (keycode == KEY_S || keycode == KEY_BACKWARD)
		cub3d->move.y = 1.0;
	if (keycode == KEY_A)
		cub3d->x_move.x = 1.0;
	else if (keycode == KEY_D)
		cub3d->x_move.y = 1.0;
	if (keycode == KEY_Q || keycode == KEY_LEFT)
		cub3d->rotate.x = 1.0;
	else if (keycode == KEY_E || keycode == KEY_RIGHT)
		cub3d->rotate.y = 1.0;
	if (keycode == KEY_LSHIFT || keycode == KEY_RSHIFT)
		cub3d->dash = 2.0;
	return (0);
}

int		key_release(int keycode, t_cub3d *cub3d)
{
	if (keycode == KEY_W || keycode == KEY_FORWARD)
		cub3d->move.x = 0.0;
	else if (keycode == KEY_S || keycode == KEY_BACKWARD)
		cub3d->move.y = 0.0;
	else if (keycode == KEY_A)
		cub3d->x_move.x = 0.0;
	else if (keycode == KEY_D)
		cub3d->x_move.y = 0.0;
	else if (keycode == KEY_Q || keycode == KEY_LEFT)
		cub3d->rotate.x = 0.0;
	else if (keycode == KEY_E || keycode == KEY_RIGHT)
		cub3d->rotate.y = 0.0;
	else if (!cub3d->space && keycode == KEY_SPACE)
		cub3d->space = FRAME_UNIT * cub3d->ani[ANI_6].count;
	else if (keycode == KEY_LSHIFT || keycode == KEY_RSHIFT)
		cub3d->dash = 1.0;
	else if (keycode == KEY_ESC)
		cub3d->exit = 1;
	else if (keycode == KEY_I)
		cub3d->option = cub3d->option ^ FLAG_UI;
	else if (keycode == KEY_L)
		cub3d->option = cub3d->option ^ FLAG_SHADOWS;
	return (0);
}

int		main_loop(t_cub3d *cub3d)
{
	static int	update;
	static int	last_opt = 0x00000011;

	if (cub3d->exit || cub3d->clear)
		return (exit_cub3d(cub3d));
	update = (last_opt != cub3d->option);
	last_opt = cub3d->option;
	if (!(++(cub3d->frame) % FRAME_UNIT))
		update = 1;
	if (cub3d->space)
	{
		if (cub3d->space == FRAME_UNIT * cub3d->ani[ANI_6].count)
			update = interaction(cub3d);
		if (!(cub3d->space)-- % FRAME_UNIT)
			update = 1;
	}
	if (cub3d->move.x || cub3d->move.y)
		update = move_camera(cub3d, (cub3d->move.x) ? 1.0 : -1.0);
	if (cub3d->x_move.x || cub3d->x_move.y)
		update = move_perp_camera(cub3d, (cub3d->x_move.x) ? 1.0 : -1.0);
	if (cub3d->rotate.x || cub3d->rotate.y)
		update = rotate_camera(cub3d, (cub3d->rotate.x) ? 0 : 1);
	update_screen(cub3d);
	return (check_clear(cub3d));
}
