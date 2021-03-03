/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvernius <mvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 14:30:57 by mvernius          #+#    #+#             */
/*   Updated: 2021/03/03 11:58:57 by mvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub3d.h"

void	ft_calc_step(t_all *all)
{
	if (all->wall_c.ray_x < 0)
	{
		all->wall_c.step_x = -1;
		all->wall_c.side_dist_x = (all->plr.pos_x - all->wall_c.map_x) \
			* all->wall_c.delta_dist_x;
	}
	else
	{
		all->wall_c.step_x = 1;
		all->wall_c.side_dist_x = (all->wall_c.map_x + 1.0 - all->plr.pos_x) \
			* all->wall_c.delta_dist_x;
	}
	if (all->wall_c.ray_y < 0)
	{
		all->wall_c.step_y = -1;
		all->wall_c.side_dist_y = (all->plr.pos_y - all->wall_c.map_y) \
			* all->wall_c.delta_dist_y;
	}
	else
	{
		all->wall_c.step_y = 1;
		all->wall_c.side_dist_y = (all->wall_c.map_y - all->plr.pos_y + 1.0) \
			* all->wall_c.delta_dist_y;
	}
}

void	ft_prepare_for_throw(t_all *all)
{
	all->wall_c.map_x = (int)all->plr.pos_x;
	all->wall_c.map_y = (int)all->plr.pos_y;
	all->wall_c.delta_dist_x = fabs(1.0 / all->wall_c.ray_x);
	all->wall_c.delta_dist_y = fabs(1.0 / all->wall_c.ray_y);
	all->wall_c.hit = 0;
	ft_calc_step(all);
}

void	ft_throw_ray(t_all *all)
{
	while (all->wall_c.hit == 0)
	{
		if (all->wall_c.side_dist_x < all->wall_c.side_dist_y)
		{
			all->wall_c.side_dist_x += all->wall_c.delta_dist_x;
			all->wall_c.map_x += all->wall_c.step_x;
			all->wall_c.side = 0;
		}
		else
		{
			all->wall_c.side_dist_y += all->wall_c.delta_dist_y;
			all->wall_c.map_y += all->wall_c.step_y;
			all->wall_c.side = 1;
		}
		if ((all->map)[all->wall_c.map_x][all->wall_c.map_y] == '1')
		{
			all->wall_c.hit = 1;
		}
	}
}

void	ft_init_ray_dir(int x, t_all *all)
{
	all->wall_c.camera_x = 2 * x / (double)(all->info.res_width) - 1;
	all->wall_c.ray_x = all->plr.dir_x + all->plr.plane_x \
		* all->wall_c.camera_x;
	all->wall_c.ray_y = all->plr.dir_y + all->plr.plane_y \
		* all->wall_c.camera_x;
}

void	ft_draw_walls(t_all *all, int x)
{
	int				y;
	unsigned int	color;

	y = -1;
	while (++y < all->wall_c.draw_start)
		ft_pix_put(all->image, x, y, all->info.ceil_col);
	while (y <= all->wall_c.draw_end)
	{
		all->wall_c.tex_y = (int)(all->wall_c.tex_pos) \
			% (all->wall_c.tex_height - 1);
		all->wall_c.tex_pos += all->wall_c.step;
		color = ft_get_color(&(all->cur_wall.w_img), \
			all->wall_c.tex_x, all->wall_c.tex_y);
		ft_pix_put(all->image, x, y, (int)color);
		y++;
	}
	while (y < all->info.res_height)
	{
		ft_pix_put(all->image, x, y, all->info.floor_col);
		y++;
	}
}
