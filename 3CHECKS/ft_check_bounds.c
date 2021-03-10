/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_bounds.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvernius <mvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 03:17:41 by mvernius          #+#    #+#             */
/*   Updated: 2021/03/03 10:55:24 by mvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub3d.h"

static int	ft_compare_symb_with_special(char c, t_all *all)
{
	char	*str;
	int		i;

	i = -1;
	str = "02SWNE";
	while (str[++i])
	{
		if (str[i] == c)
		{
			if (c == '0' || c == '2')
				return (1);
			else
				return (ft_set_player_dir(c, all));
		}
	}
	if (c == '2')
	{
		all->info.spr_sum++;
	}
	if (c != '1' && c != '2' && c != ' ' && c != '\n')
		ft_close_if_error("Error\nwrong symbols in the map");
	return (0);
}

static void	ft_check_neighbours(char **map, int i, int j)
{
	int	row;
	int	col;
	int	count_row;
	int	count_col;

	row = i - 1;
	col = j - 1;
	count_row = -1;
	while (++count_row < 3)
	{
		count_col = -1;
		while (++count_col < 3)
		{
			if (map[row + count_row][col + count_col] == ' ')
				ft_close_if_error("Error\nmap isn't surrounded");
		}
	}
}

void		ft_check_bounds2(char **map, int i, int *parse_flag, t_all *all)
{
	int		check;
	int		j;

	j = -1;
	while (++j < all->max_str_len + 2)
	{
		check = ft_compare_symb_with_special(map[i][j], all);
		if (check)
			ft_check_neighbours(map, i, j);
		if (check == 2 && *parse_flag == 1)
			ft_close_if_error("Error\nmore than one player was given");
		if (check == 2)
		{
			all->plr.pos_x = i + 0.5;
			all->plr.pos_y = j + 0.5;
			all->map[i][j] = '0';
			*parse_flag = 1;
			check = 0;
		}
	}
}

void		ft_check_bounds(char **map, t_all *all)
{
	int	i;
	int	parse_flag;

	parse_flag = 0;
	i = -1;
	while (++i < all->map_size)
	{
		ft_check_bounds2(map, i, &parse_flag, all);
	}
	if (!parse_flag)
		ft_close_if_error("Error\nplayer does not exist");
}
