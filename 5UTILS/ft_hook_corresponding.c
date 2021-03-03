/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_corresponding.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvernius <mvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 17:36:43 by mvernius          #+#    #+#             */
/*   Updated: 2021/03/03 11:39:08 by mvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub3d.h"

int	ft_event(t_all *all)
{
	if (all->keys.esc)
		ft_close(all);
	if (all->keys.left)
		ft_move_left(all);
	if (all->keys.frwd)
		ft_move_frwd(all);
	if (all->keys.back)
		ft_move_back(all);
	if (all->keys.right)
		ft_move_right(all);
	if (all->keys.rr)
		ft_rotate_right(all);
	if (all->keys.rl)
		ft_rotate_left(all);
	if (all->keys.left || all->keys.frwd || all->keys.back || all->keys.right \
		|| all->keys.rr || all->keys.rl)
		ft_draw_screen(all);
	return (1);
}

int	ft_key_press(int code, t_all *all)
{
	if (code == 0)
		all->keys.left = 1;
	if (code == 1)
		all->keys.back = 1;
	if (code == 2)
		all->keys.right = 1;
	if (code == 13)
		all->keys.frwd = 1;
	if (code == 123)
		all->keys.rl = 1;
	if (code == 124)
		all->keys.rr = 1;
	if (code == 53)
		all->keys.esc = 1;
	return (1);
}

int	ft_key_release(int code, t_all *all)
{
	if (code == 1)
		all->keys.back = 0;
	if (code == 13)
		all->keys.frwd = 0;
	if (code == 0)
		all->keys.left = 0;
	if (code == 2)
		all->keys.right = 0;
	if (code == 123)
		all->keys.rl = 0;
	if (code == 124)
		all->keys.rr = 0;
	return (1);
}
