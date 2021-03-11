/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvernius <mvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 02:05:00 by mvernius          #+#    #+#             */
/*   Updated: 2021/03/11 22:12:51 by mvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub3d.h"

static void	ft_global_init(t_all *all)
{
	all->image = (t_img *)malloc(sizeof(t_img));
	if (NULL == all->image)
		ft_close_if_error("ERROR: allocating image\n");
	all->win.mlx = mlx_init();
	all->win.win = mlx_new_window(all->win.mlx, \
		all->info.res_width, all->info.res_height, "CUB3D");
	all->image->img = mlx_new_image(all->win.mlx, \
		all->info.res_width, all->info.res_height);
	all->image->addr = mlx_get_data_addr(all->image->img, \
		&(all->image->bpp), &(all->image->line_l), &(all->image->end));
	all->z_buf = (double *)malloc(sizeof(double) * (all->info.res_width + 1));
	if (NULL == all->z_buf)
		ft_close_if_error("ERROR: allocating z_buf\n");
	ft_init_plr_plane(all);
	ft_init_all_textures(all);
	ft_init_sprite(all);
}

void		ft_raycast(t_all *all)
{
	ft_draw_screen(all);
	mlx_hook(all->win.win, 2, 0, ft_key_press, all);
	mlx_hook(all->win.win, 3, 0, ft_key_release, all);
	mlx_loop_hook(all->win.mlx, ft_event, all);
	mlx_hook(all->win.win, 17, 0, ft_close, all);
	mlx_loop(all->win.mlx);
}

int			main(int argc, char **argv)
{
	t_all	*all;

	all = (t_all *)malloc(sizeof(t_all));
	if (NULL == all)
		ft_close_if_error("ERROR: allocating all in main");
	if (argc > 1 && argc < 4)
	{
		if (argc == 3 && ft_strncmp(argv[2], "--save", 7))
			ft_close_if_error("Error\nwrong second argument\n");
		ft_parser(argv[1], all);
		ft_global_init(all);
		if (argc == 2)
			ft_raycast(all);
		else
			ft_make_bmp(all);
	}
	else
		ft_close_if_error("ERROR: wrong number of arguments\n");
	return (0);
}
