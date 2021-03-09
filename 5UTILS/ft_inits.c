/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvernius <mvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 01:41:00 by mvernius          #+#    #+#             */
/*   Updated: 2021/03/09 22:21:26 by mvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub3d.h"

void		ft_init_sprite(t_all *all)
{
	t_spr_info	sprite;

	sprite.s_img.img = mlx_xpm_file_to_image(all->win.mlx, \
		all->info.spr_path, &(sprite.width), &(sprite.height));
	sprite.s_img.addr = mlx_get_data_addr(sprite.s_img.img, \
		&(sprite.s_img.bpp), &(sprite.s_img.line_l), &(sprite.s_img.end));
	all->sprite = sprite;
}

void		ft_convert_file_to_image(t_all *all)
{
	all->textures.north.w_img.img = mlx_xpm_file_to_image(all->win.mlx, all->info.north_path, &(all->textures.north.width), &(all->textures.north.height));
	all->textures.south.w_img.img = mlx_xpm_file_to_image(all->win.mlx, all->info.south_path, &(all->textures.south.width), &(all->textures.south.height));
	all->textures.west.w_img.img = mlx_xpm_file_to_image(all->win.mlx, all->info.west_path, &(all->textures.west.width), &(all->textures.west.height));
	all->textures.east.w_img.img = mlx_xpm_file_to_image(all->win.mlx, all->info.east_path, &(all->textures.east.width), &(all->textures.east.height));
}

void		ft_get_addr(t_all_tex *textures)
{
	textures->north.w_img.addr = mlx_get_data_addr(textures->north.w_img.img, &(textures->north.w_img.bpp), &(textures->north.w_img.line_l), &(textures->north.w_img.end));
	textures->south.w_img.addr = mlx_get_data_addr(textures->south.w_img.img, &(textures->south.w_img.bpp), &(textures->south.w_img.line_l), &(textures->south.w_img.end));
	textures->west.w_img.addr = mlx_get_data_addr(textures->west.w_img.img, &(textures->west.w_img.bpp), &(textures->west.w_img.line_l), &(textures->west.w_img.end));
	textures->east.w_img.addr = mlx_get_data_addr(textures->east.w_img.img, &(textures->east.w_img.bpp), &(textures->east.w_img.line_l), &(textures->east.w_img.end));
}

static void	ft_check_conversion(t_all *all)
{
	if (all->textures.east.w_img.img == NULL)
		ft_close_if_error("Error:\neast img isn't created\n");
	if (all->textures.north.w_img.img == NULL)
		ft_close_if_error("Error:\nnorth img isn't created\n");
	if (all->textures.west.w_img.img == NULL)
		ft_close_if_error("Error:\nwest img isn't created\n");
	if (all->textures.south.w_img.img == NULL)
		ft_close_if_error("Error:\nsouth img isn't created\n");
}

void		ft_init_all_textures(t_all *all)
{
	ft_convert_file_to_image(all);
	ft_check_conversion(all);
	ft_get_addr(&(all->textures));
}
