/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_plr_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvernius <mvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 01:48:49 by mvernius          #+#    #+#             */
/*   Updated: 2021/02/21 01:52:51 by mvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub3d.h"

void	ft_init_plr_plane(t_all *all)
{
	if (all->player_dir == 'W')
	{
		all->plr.plane_x = 0.0;
		all->plr.plane_y = 0.66;
	}
	if (all->player_dir == 'S')
	{
		all->plr.plane_x = -0.66;
		all->plr.plane_y = 0.0;
	}
	if (all->player_dir == 'E')
	{
		all->plr.plane_x = 0.0;
		all->plr.plane_y = -0.66;
	}
	if (all->player_dir == 'N')
	{
		all->plr.plane_x = 0.66;
		all->plr.plane_y = 0.0;
	}
}
