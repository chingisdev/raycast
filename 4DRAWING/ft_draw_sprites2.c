/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sprites2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvernius <mvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 23:35:33 by mvernius          #+#    #+#             */
/*   Updated: 2021/03/03 11:58:33 by mvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub3d.h"

void	ft_swap_sprites(t_all *all, int i, int j)
{
	t_sprite	temp;

	temp = all->spr_arr[i];
	all->spr_arr[i] = all->spr_arr[j];
	all->spr_arr[j] = temp;
}

void	ft_quicksort_spr_arr(t_all *all, int first, int last)
{
	int			i;
	int			j;
	int			mid;

	if (first < last)
	{
		mid = first;
		i = first;
		j = last;
		while (i < j)
		{
			while (all->spr_arr[i].dist >= all->spr_arr[mid].dist && i < last)
				i++;
			while (all->spr_arr[j].dist < all->spr_arr[mid].dist)
				j--;
			if (i < j)
				ft_swap_sprites(all, i, j);
		}
		ft_swap_sprites(all, mid, j);
		ft_quicksort_spr_arr(all, j + 1, last);
		ft_quicksort_spr_arr(all, first, j - 1);
	}
}

void	draw_stripes2(t_all *all, int stripe, t_spr_info *spr)
{
	int				i;
	int				d;
	unsigned int	color;
	t_sprite_cast	*cast;

	cast = &(all->spr_c);
	i = cast->draw_start_y;
	while (i < cast->draw_end_y)
	{
		d = i * 256 - all->info.res_height * 128 + cast->spr_height * 128;
		cast->spr_y = ((d * all->sprite.height) / cast->spr_height) / 256;
		color = ft_get_color(&(spr->s_img), cast->spr_x, cast->spr_y);
		if ((color & 0x00FFFFFF) != 0)
		{
			ft_pix_put(all->image, stripe, i, (int)color);
		}
		i++;
	}
}
