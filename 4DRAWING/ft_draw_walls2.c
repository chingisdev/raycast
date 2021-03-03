/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_walls2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvernius <mvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 23:23:09 by mvernius          #+#    #+#             */
/*   Updated: 2021/03/03 11:32:00 by mvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub3d.h"

void	ft_find_perp(t_all *all)
{
	if (all->wall_c.side == 0)
	{
		all->wall_c.perp_wall_dist = (all->wall_c.map_x - all->plr.pos_x + \
			(1 - all->wall_c.step_x) / 2) / all->wall_c.ray_x;
	}
	else
	{
		all->wall_c.perp_wall_dist = (all->wall_c.map_y - all->plr.pos_y + \
			(1 - all->wall_c.step_y) / 2) / all->wall_c.ray_y;
	}
}

void	ft_detect_texture(t_all *all)
{
	if (all->wall_c.side == 0)
	{
		if (all->wall_c.ray_x < 0.0)
			all->cur_wall = all->textures.west;
		else
			all->cur_wall = all->textures.east;
	}
	else
	{
		if (all->wall_c.ray_y > 0.0)
			all->cur_wall = all->textures.north;
		else
			all->cur_wall = all->textures.south;
	}
}

void	ft_detect_tex_x(t_all *all)
{
	int	tex_width;

	tex_width = all->cur_wall.width;
	all->wall_c.tex_x = (int)(all->wall_c.wall_x * (1.0 * tex_width));
	if (all->wall_c.side == 0 && all->wall_c.ray_x > 0)
	{
		all->wall_c.tex_x = tex_width - all->wall_c.tex_x - 1;
	}
	if (all->wall_c.side == 1 && all->wall_c.ray_y < 0)
	{
		all->wall_c.tex_x = tex_width - all->wall_c.tex_x - 1;
	}
}

void	ft_detect_wall_pos(t_all *all)
{
	if (all->wall_c.side == 0)
	{
		all->wall_c.wall_x = all->plr.pos_y + all->wall_c.perp_wall_dist \
			* all->wall_c.ray_y;
	}
	else
	{
		all->wall_c.wall_x = all->plr.pos_x + all->wall_c.perp_wall_dist \
			* all->wall_c.ray_x;
	}
	all->wall_c.wall_x -= floor(all->wall_c.wall_x);
}

void	ft_find_wall_height(t_all *all)
{
	all->wall_c.line_height = (int)(all->info.res_height \
		/ all->wall_c.perp_wall_dist);
	all->wall_c.draw_start = (all->wall_c.line_height * -1) \
		/ 2 + all->info.res_height / 2;
	if (all->wall_c.draw_start < 0)
	{
		all->wall_c.draw_start = 0;
	}
	all->wall_c.draw_end = all->info.res_height \
		/ 2 + all->wall_c.line_height / 2;
	if (all->wall_c.draw_end >= all->info.res_height \
		|| all->wall_c.draw_end < 0)
	{
		all->wall_c.draw_end = all->info.res_height - 1;
	}
}
