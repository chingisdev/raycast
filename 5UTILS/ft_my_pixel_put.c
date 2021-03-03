/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_pixel_put.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvernius <mvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 18:40:39 by mvernius          #+#    #+#             */
/*   Updated: 2021/03/03 11:37:54 by mvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub3d.h"

void			ft_pix_put(t_img *img, int x, int y, unsigned int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_l + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

unsigned int	ft_get_color(t_img *img, int x, int y)
{
	char			*dst;
	unsigned int	color;

	dst = img->addr + y * img->line_l + x * img->bpp / 8;
	color = *(unsigned int *)dst;
	return (color);
}
