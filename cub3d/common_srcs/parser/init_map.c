/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:11:05 by ijang             #+#    #+#             */
/*   Updated: 2020/11/18 13:29:46 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_map_size(t_loca *s, t_loca *e, t_strlst *buffer)
{
	int		i;
	int		flag;

	while (buffer)
	{
		i = -1;
		flag = 1;
		while (s->y == -1 && buffer->text[++i])
			if (buffer->text[i] != ' ')
				set_loca(s, i--, e->y);
		while (s->y != -1 && buffer->text[++i])
			if (buffer->text[i] != ' ')
			{
				flag = 0;
				if (s->x > i)
					s->x = i;
				else if (e->x <= i)
					e->x = i + 1;
			}
		buffer = buffer->next;
		++(e->y);
		if (s->y != -1 && flag)
			break ;
	}
	return (1);
}

static int	check_valid_char(t_strlst *buffer, int start, int last)
{
	int		i;

	while (start-- && --last && buffer)
		buffer = buffer->next;
	if (start != -1)
		return (0);
	while (++start < last && buffer)
	{
		i = -1;
		while (buffer->text[++i])
			if (!(ft_strchr(VALID_MAP_CHARACTERS, buffer->text[i])))
				return (0);
		buffer = buffer->next;
	}
	if (start != last)
		return (0);
	while (buffer)
	{
		i = -1;
		while (buffer->text[++i])
			if (buffer->text[i] != ' ')
				return (0);
		buffer = buffer->next;
	}
	return (1);
}

static int	copy_map(t_loca size, t_loca start, t_strlst *buffer, int *map)
{
	int		i;
	int		camera;

	camera = 0;
	while ((start.y)--)
		buffer = buffer->next;
	while (++(start.y) < size.y && buffer)
	{
		i = start.x;
		while (buffer->text[i] && i < size.x + start.x)
		{
			if (ft_strchr("NSEW", buffer->text[i]))
				++camera;
			map[(size.x * start.y) + i] = buffer->text[i];
			++i;
		}
		while (i < size.x + start.x)
			map[(size.x * start.y) + i++] = ' ';
		buffer = buffer->next;
	}
	return (camera);
}

static int	check_wall(t_loca map_size, int *map)
{
	int		i;
	int		j;

	i = -1;
	while (++i < map_size.y)
	{
		j = -1;
		while (++j < map_size.x)
			if (map[i * map_size.x + j] != ' '
				&& map[i * map_size.x + j] != '1')
				if (i == 0 || i == map_size.y - 1
					|| j == 0 || j == map_size.x - 1
					|| map[(i - 1) * map_size.x + (j - 1)] == ' '
					|| map[(i - 1) * map_size.x + j] == ' '
					|| map[(i - 1) * map_size.x + (j + 1)] == ' '
					|| map[i * map_size.x + (j - 1)] == ' '
					|| map[i * map_size.x + (j + 1)] == ' '
					|| map[(i + 1) * map_size.x + (j - 1)] == ' '
					|| map[(i + 1) * map_size.x + j] == ' '
					|| map[(i + 1) * map_size.x + (j + 1)] == ' ')
					return (0);
	}
	return (1);
}

int			map_parsing(t_cub3d *cub3d, t_strlst *buffer)
{
	int		*map;
	t_loca	start;
	t_loca	end;

	set_loca(&start, -1, -1);
	set_loca(&end, 0, 0);
	if (!buffer || !check_map_size(&start, &end, buffer)
		|| (cub3d->map_size.x = end.x - start.x) <= 2
		|| (cub3d->map_size.y = end.y - start.y) <= 2
		|| !check_valid_char(buffer, start.y, end.y))
		return (4);
	map = (int *)malloc(sizeof(int) * (cub3d->map_size.x * cub3d->map_size.y));
	if (!map)
		return (9);
	if (copy_map(cub3d->map_size, start, buffer, map) != 1
		|| !check_wall(cub3d->map_size, map))
	{
		free(map);
		return (4);
	}
	cub3d->map = map;
	return (0);
}
