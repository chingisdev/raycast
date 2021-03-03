/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvernius <mvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 18:22:25 by mvernius          #+#    #+#             */
/*   Updated: 2021/03/03 11:31:28 by mvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub3d.h"

void	init_spr_arrays(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->info.spr_sum)
	{
		all->spr_arr[i].dist = ((all->plr.pos_x - (all->spr_arr)[i].x) \
			* (all->plr.pos_x - (all->spr_arr)[i].x) \
			+ (all->plr.pos_y - (all->spr_arr)[i].y) \
			* (all->plr.pos_y - (all->spr_arr)[i].y));
		i++;
	}
}

void	make_pos_relative(t_all *all, int i)
{
	all->spr_c.sprite_x = (all->spr_arr)[i].x - all->plr.pos_x;
	all->spr_c.sprite_y = (all->spr_arr)[i].y - all->plr.pos_y;
}

void	transform_sprite(t_all *all)
{
	all->spr_c.inv_det = 1.0 / (all->plr.plane_x * all->plr.dir_y \
		- all->plr.dir_x * all->plr.plane_y);
	all->spr_c.trans_x = all->spr_c.inv_det * (all->plr.dir_y \
		* all->spr_c.sprite_x - all->plr.dir_x * all->spr_c.sprite_y);
	all->spr_c.trans_y = all->spr_c.inv_det * (all->plr.plane_x \
		* all->spr_c.sprite_y - all->plr.plane_y * all->spr_c.sprite_x);
}

void	prepare_to_draw(t_all *all)
{
	all->spr_c.spr_screen_x = (int)((all->info.res_width / 2) \
		* (1 + all->spr_c.trans_x / all->spr_c.trans_y));
	all->spr_c.spr_height = \
		abs((int)(all->info.res_height / all->spr_c.trans_y));
	all->spr_c.draw_start_y = -all->spr_c.spr_height / 2 \
		+ all->info.res_height / 2;
	if (all->spr_c.draw_start_y < 0)
		all->spr_c.draw_start_y = 0;
	all->spr_c.draw_end_y = all->spr_c.spr_height / 2 \
		+ all->info.res_height / 2;
	if (all->spr_c.draw_end_y >= all->info.res_height)
		all->spr_c.draw_end_y = all->info.res_height - 1;
	all->spr_c.spr_width = abs((int)(all->info.res_width / all->spr_c.trans_y));
	all->spr_c.draw_start_x = -all->spr_c.spr_width / 2 \
		+ all->spr_c.spr_screen_x;
	if (all->spr_c.draw_start_x < 0)
		all->spr_c.draw_start_x = 0;
	all->spr_c.draw_end_x = all->spr_c.spr_width / 2 + all->spr_c.spr_screen_x;
	if (all->spr_c.draw_end_x >= all->info.res_width)
		all->spr_c.draw_end_x = all->info.res_width - 1;
}

void	draw_sprites(t_all *all)
{
	int				stripe;

	stripe = all->spr_c.draw_start_x;
	while (stripe < all->spr_c.draw_end_x)
	{
		all->spr_c.spr_x = (int)(256 * (stripe - \
			(-all->spr_c.spr_width / 2 + all->spr_c.spr_screen_x)) \
			* all->sprite.width / all->spr_c.spr_width) / 256;
		if (all->spr_c.trans_y > 0 && stripe > 0 && stripe \
			< all->info.res_width && all->spr_c.trans_y < all->z_buf[stripe])
		{
			draw_stripes2(all, stripe, &(all->sprite));
		}
		stripe++;
	}
}
