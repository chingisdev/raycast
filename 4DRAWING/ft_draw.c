/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvernius <mvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:02:05 by mvernius          #+#    #+#             */
/*   Updated: 2021/03/03 11:58:42 by mvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub3d.h"

void	ft_prepare_tex(t_all *all)
{
	ft_detect_tex_x(all);
	all->wall_c.tex_height = all->cur_wall.height;
	all->wall_c.step = 1.0 * all->wall_c.tex_height / all->wall_c.line_height;
	all->wall_c.tex_pos = (all->wall_c.draw_start - 1.0
			* all->info.res_height / 2
			+ 1.0 * all->wall_c.line_height / 2) * all->wall_c.step;
}

void	ft_wall_casting(t_all *all)
{
	int	x;

	x = 0;
	while (x < all->info.res_width)
	{
		ft_init_ray_dir(x, all);
		ft_prepare_for_throw(all);
		ft_throw_ray(all);
		ft_find_perp(all);
		ft_find_wall_height(all);
		ft_detect_wall_pos(all);
		ft_detect_texture(all);
		ft_prepare_tex(all);
		(all->z_buf)[x] = all->wall_c.perp_wall_dist;
		ft_draw_walls(all, x);
		x++;
	}
}

void	ft_sprite_casting(t_all *all)
{
	int	i;

	init_spr_arrays(all);
	ft_quicksort_spr_arr(all, 0, all->info.spr_sum - 1);
	i = 0;
	while (i < all->info.spr_sum)
	{
		make_pos_relative(all, i);
		transform_sprite(all);
		prepare_to_draw(all);
		draw_sprites(all);
		i++;
	}
}

void	ft_draw_screen(t_all *all)
{
	mlx_destroy_image(all->win.mlx, all->image->img);
	all->image->img = mlx_new_image(all->win.mlx, \
		all->info.res_width, all->info.res_height);
	all->image->addr = mlx_get_data_addr(all->image->img, \
		&(all->image->bpp), &(all->image->line_l), &(all->image->end));
	ft_wall_casting(all);
	ft_sprite_casting(all);
	mlx_put_image_to_window(all->win.mlx, all->win.win, all->image->img, 0, 0);
}
