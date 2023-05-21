/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 20:36:02 by ijang             #+#    #+#             */
/*   Updated: 2020/11/18 12:15:01 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int
	ft_put_file_header(t_window *w, int fd)
{
	int				n;
	unsigned char	header[14];

	n = 0;
	while (n < 14)
		header[n++] = (unsigned char)(0);
	header[0] = (unsigned char)(66);
	header[1] = (unsigned char)(77);
	n = w->size.x * w->size.y * 4 + 54;
	header[2] = (unsigned char)(n % 256);
	header[3] = (unsigned char)(n / 256 % 256);
	header[4] = (unsigned char)(n / 256 / 256 % 256);
	header[5] = (unsigned char)(n / 256 / 256 / 256);
	header[10] = (unsigned char)54;
	return (write(fd, header, 14) < 0);
}

static int
	ft_put_info_header(t_window *w, int fd)
{
	int				n;
	unsigned char	header[40];

	n = 0;
	while (n < 40)
		header[n++] = (unsigned char)(0);
	header[0] = (unsigned char)(40);
	n = w->size.x;
	header[4] = (unsigned char)(n % 256);
	header[5] = (unsigned char)(n / 256 % 256);
	header[6] = (unsigned char)(n / 256 / 256 % 256);
	header[7] = (unsigned char)(n / 256 / 256 / 256);
	n = w->size.y;
	header[8] = (unsigned char)(n % 256);
	header[9] = (unsigned char)(n / 256 % 256);
	header[10] = (unsigned char)(n / 256 / 256 % 256);
	header[11] = (unsigned char)(n / 256 / 256 / 256);
	header[12] = (unsigned char)(1);
	header[14] = (unsigned char)(32);
	return (write(fd, header, 40) < 0);
}

static int
	ft_put_data(int *data, t_loca *size, int fd)
{
	int				i;
	int				j;
	unsigned char	buffer[4];

	i = size->x * (size->y - 1);
	while (0 <= i)
	{
		j = 0;
		while (j < size->x)
		{
			buffer[0] = (unsigned char)(data[i] % 256);
			buffer[1] = (unsigned char)(data[i] / 256 % 256);
			buffer[2] = (unsigned char)(data[i] / 256 / 256 % 256);
			buffer[3] = (unsigned char)(0);
			if (write(fd, buffer, 4) < 0)
				return (1);
			i++;
			j++;
		}
		i -= 2 * size->x;
	}
	return (0);
}

int
	save_bmp(t_cub3d *cub3d)
{
	int			fd;
	t_window	*w;

	if ((fd = open("screenshot.bmp\0", O_CREAT | O_TRUNC | O_RDWR, 0644)) <= 0)
		return (0);
	w = &cub3d->window;
	if (ft_put_file_header(w, fd))
		return (0);
	if (ft_put_info_header(w, fd))
		return (0);
	if (ft_put_data(w->screen.data, &w->size, fd))
		return (0);
	close(fd);
	return (1);
}
