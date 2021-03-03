/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_player_dir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvernius <mvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 03:17:41 by mvernius          #+#    #+#             */
/*   Updated: 2021/02/26 01:05:58 by mvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub3d.h"

int	ft_set_player_dir(char c, t_all *all)
{
	all->player_dir = c;
	if (c == 'N')
	{
		all->plr.dir_x = 0;
		all->plr.dir_y = 1;
	}
	else if (c == 'S')
	{
		all->plr.dir_x = 0;
		all->plr.dir_y = -1;
	}
	else if (c == 'E')
	{
		all->plr.dir_x = 1;
		all->plr.dir_y = 0;
	}
	else if (c == 'W')
	{
		all->plr.dir_x = -1;
		all->plr.dir_y = 0;
	}
	return (2);
}
