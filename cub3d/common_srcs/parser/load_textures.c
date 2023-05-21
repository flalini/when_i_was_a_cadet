/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 22:35:36 by ijang             #+#    #+#             */
/*   Updated: 2020/11/16 22:42:17 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	load_tex(t_window *window, t_tex *tex, char *path)
{
	if ((tex->tex = mlx_xpm_file_to_image(window->mlx,
		path, &tex->size.x, &tex->size.y)))
		tex->data = (int *)mlx_get_data_addr(tex->tex,
			&tex->bpp, &tex->size_l, &tex->endian);
	else
		return (1);
	return (0);
}

int			clear_textures(t_cub3d *cub3d)
{
	int	i;

	i = -1;
	while (++i < TEXTURES_NUM)
	{
		if (cub3d->tex[i].tex)
			mlx_destroy_image(cub3d->window.mlx, cub3d->tex[i].tex);
		cub3d->tex[i].tex = NULL;
		cub3d->tex[i].data = NULL;
	}
	return (0);
}

int			clear_animations(t_cub3d *cub3d)
{
	int		i;
	int		j;

	clear_textures(cub3d);
	i = -1;
	while (++i < ANIMATION_NUM)
		if (cub3d->ani[i].tex)
		{
			j = -1;
			while (++j < cub3d->ani[i].count)
				if (cub3d->ani[i].tex[j].tex)
					mlx_destroy_image(cub3d->window.mlx,
						cub3d->ani[i].tex[j].tex);
			free(cub3d->ani[i].tex);
			cub3d->ani[i].tex = NULL;
		}
	return (0);
}

int			load_animations(t_cub3d *c, t_pars *p)
{
	int		i;
	int		j;
	t_tex	*new;

	i = -1;
	while (++i < ANIMATION_NUM)
		if (p->ani_path[i] && !(j = 0))
		{
			while (p->ani_path[i][++j])
				c->ani[i].count = j;
			if (!(new = (t_tex *)malloc(sizeof(t_tex) * j--)))
				return (clear_animations(c));
			c->ani[i].tex = new;
			while (j--)
			{
				if (load_tex(&c->window, &new[j], p->ani_path[i][j + 1]))
				{
					while (j--)
						new[j].tex = NULL;
					return (clear_animations(c));
				}
				find_texture_empty(&new[j]);
			}
		}
	return (1);
}

int			load_textures(t_cub3d *c, t_pars *p)
{
	int	i;

	i = -1;
	while (++i < TEX_SPRITE)
		if (p->tex_path[i] && load_tex(&c->window, &c->tex[i], p->tex_path[i]))
			return (clear_textures(c));
	if (!(p->tex_path[i]))
		return (1);
	if (load_tex(&c->window, &c->tex[i], p->tex_path[i]))
		return (clear_textures(c));
	find_texture_empty(&c->tex[i]);
	return (1);
}
