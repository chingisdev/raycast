/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvernius <mvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 01:51:25 by mvernius          #+#    #+#             */
/*   Updated: 2021/03/03 11:38:48 by mvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub3d.h"

void	ft_rotate_right(t_all *all)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = all->plr.dir_x;
	all->plr.dir_x = all->plr.dir_x * cos(-0.03) - all->plr.dir_y * sin(-0.03);
	all->plr.dir_y = old_dir_x * sin(-0.03) + all->plr.dir_y * cos(-0.03);
	old_plane_x = all->plr.plane_x;
	all->plr.plane_x = all->plr.plane_x * cos(-0.03) \
		- all->plr.plane_y * sin(-0.03);
	all->plr.plane_y = old_plane_x * sin(-0.03) + all->plr.plane_y * cos(-0.03);
}

void	ft_rotate_left(t_all *all)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = all->plr.dir_x;
	all->plr.dir_x = all->plr.dir_x * cos(0.03) - all->plr.dir_y * sin(0.03);
	all->plr.dir_y = old_dir_x * sin(0.03) + all->plr.dir_y * cos(0.03);
	old_plane_x = all->plr.plane_x;
	all->plr.plane_x = all->plr.plane_x * cos(0.03) \
		- all->plr.plane_y * sin(0.03);
	all->plr.plane_y = old_plane_x * sin(0.03) + all->plr.plane_y * cos(0.03);
}
