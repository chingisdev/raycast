/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_motions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvernius <mvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 01:47:13 by mvernius          #+#    #+#             */
/*   Updated: 2021/02/26 01:58:31 by mvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub3d.h"

void	ft_move_left(t_all *all)
{
	if (all->map[(int)(all->plr.pos_x - all->plr.dir_y * 0.05)]
		[(int)(all->plr.pos_y)] == '0')
	{
		all->plr.pos_x -= all->plr.dir_y * 0.05;
	}
	if (all->map[(int)(all->plr.pos_x)]
		[(int)(all->plr.pos_y + all->plr.dir_x * 0.05)] == '0')
	{
		all->plr.pos_y += all->plr.dir_x * 0.05;
	}
}

void	ft_move_right(t_all *all)
{
	if (all->map[(int)(all->plr.pos_x + all->plr.dir_y * 0.05)]
		[(int)(all->plr.pos_y)] == '0')
	{
		all->plr.pos_x += all->plr.dir_y * 0.05;
	}
	if (all->map[(int)(all->plr.pos_x)]
		[(int)(all->plr.pos_y - all->plr.dir_x * 0.05)] == '0')
	{
		all->plr.pos_y -= all->plr.dir_x * 0.05;
	}
}

void	ft_move_frwd(t_all *all)
{
	if (all->map[(int)(all->plr.pos_x + all->plr.dir_x * 0.05)]
		[(int)all->plr.pos_y] == '0')
	{
		all->plr.pos_x += all->plr.dir_x * 0.05;
	}
	if (all->map[(int)all->plr.pos_x]
		[(int)(all->plr.pos_y + all->plr.dir_y * 0.05)] == '0')
	{
		all->plr.pos_y += all->plr.dir_y * 0.05;
	}
}

void	ft_move_back(t_all *all)
{
	if (all->map[(int)(all->plr.pos_x - all->plr.dir_x * 0.05)]
		[(int)all->plr.pos_y] == '0')
	{
		all->plr.pos_x -= all->plr.dir_x * 0.05;
	}
	if (all->map[(int)all->plr.pos_x]
		[(int)(all->plr.pos_y - all->plr.dir_y * 0.05)] == '0')
	{
		all->plr.pos_y -= all->plr.dir_y * 0.05;
	}
}
