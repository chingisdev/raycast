/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvernius <mvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:38:12 by mvernius          #+#    #+#             */
/*   Updated: 2021/03/03 11:58:47 by mvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub3d.h"

static void	ft_free_info(t_all *all)
{
	if (all->info.ceiling != NULL)
		free(all->info.ceiling);
	if (all->info.east_path != NULL)
		free(all->info.east_path);
	if (all->info.floor != NULL)
		free(all->info.floor);
	if (all->info.north_path != NULL)
		free(all->info.north_path);
	if (all->info.res != NULL)
		free(all->info.res);
	if (all->info.south_path != NULL)
		free(all->info.south_path);
	if (all->info.spr_path != NULL)
		free(all->info.spr_path);
	if (all->info.west_path != NULL)
		free(all->info.west_path);
}

int			ft_close(t_all *all)
{
	ft_make_free(all);
	exit(0);
}

void		ft_my_free2(int len, char **matrix)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(matrix[i]);
		matrix[i] = NULL;
		i++;
	}
	free(matrix);
}

void		ft_make_free(t_all *all)
{
	if (!all)
	{
		mlx_destroy_image(all->win.mlx, all->image->img);
		if (all->spr_arr != NULL)
			free(all->spr_arr);
		ft_free_info(all);
		if (all->map != NULL)
			ft_my_free2((size_t)all->map_size, all->map);
		if (all->z_buf != NULL)
			free(all->z_buf);
		if (all->spr_dist != NULL)
			free(all->spr_dist);
		if (all->spr_order != NULL)
			free(all->spr_order);
		free(all);
	}
}
