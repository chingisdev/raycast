/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_bmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvernius <mvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:29:46 by mvernius          #+#    #+#             */
/*   Updated: 2021/03/03 13:39:56 by mvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub3d.h"

void	ft_create_header(int fd, int bmp_size)
{
	unsigned char	bmp_file_header[14];

	ft_bzero(bmp_file_header, 14);
	bmp_file_header[0] = (unsigned char)('B');
	bmp_file_header[1] = (unsigned char)('M');
	bmp_file_header[2] = (unsigned char)(bmp_size);
	bmp_file_header[3] = (unsigned char)(bmp_size >> 8);
	bmp_file_header[4] = (unsigned char)(bmp_size >> 16);
	bmp_file_header[5] = (unsigned char)(bmp_size >> 24);
	bmp_file_header[10] = (unsigned char)(54);
	write(fd, bmp_file_header, 14);
}

void	ft_create_info(t_all *all, int fd)
{
	unsigned char	bmp_info_header[40];

	ft_bzero(bmp_info_header, 40);
	bmp_info_header[0] = (unsigned char)(40);
	bmp_info_header[4] = (unsigned char)(all->info.res_width);
	bmp_info_header[5] = (unsigned char)(all->info.res_width >> 8);
	bmp_info_header[6] = (unsigned char)(all->info.res_width >> 16);
	bmp_info_header[7] = (unsigned char)(all->info.res_width >> 24);
	bmp_info_header[8] = (unsigned char)(all->info.res_height);
	bmp_info_header[9] = (unsigned char)(all->info.res_height >> 8);
	bmp_info_header[10] = (unsigned char)(all->info.res_height >> 16);
	bmp_info_header[11] = (unsigned char)(all->info.res_height >> 24);
	bmp_info_header[12] = (unsigned char)(1);
	bmp_info_header[14] = (unsigned char)(32);
	write(fd, bmp_info_header, 40);
}

void	ft_make_bmp(t_all *all)
{
	int				fd;
	int				bmp_size;
	int				height;
	int				line_len;

	fd = open("snapshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0655);
	if (fd < 0)
	{
		ft_close_if_error("ERROR: can't make snapshot.bmp\n");
	}
	ft_draw_screen(all);
	bmp_size = 14 + 40 + (4 * all->info.res_height * all->info.res_width);
	ft_create_header(fd, bmp_size);
	ft_create_info(all, fd);
	height = all->info.res_height;
	line_len = all->info.res_width * all->image->bpp / 8;
	while (height > -1)
	{
		write(fd, (unsigned char *)(all->image->addr \
			+ height * all->image->line_l), line_len);
		height--;
	}
	close(fd);
}
