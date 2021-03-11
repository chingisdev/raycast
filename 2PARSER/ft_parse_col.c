/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_col.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvernius <mvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:08:47 by mvernius          #+#    #+#             */
/*   Updated: 2021/03/10 16:27:43 by mvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub3d.h"

void		ft_parse_col(char *s, int *color)
{
	int		check;
	int		i;
	int		tmp;
	int		shift;

	shift = 8;
	tmp = 0;
	i = 3;
	check = 0;
	while (--i >= 0)
	{
		s += ft_atoi_modif(s, &tmp, &check);
		if (tmp < 0 || tmp > 255)
			ft_close_if_error("Error\nwrong value for floor color\n");
		*color = *color | (tmp << (shift * i));
	}
	if (check == 3 && *s != '\0')
		ft_close_if_error("Error\nwrong symbols after num\n");
	if (check != 3)
		ft_close_if_error("Error\nwrong number values in string\n");
}

void		ft_check_fill_floor_col(t_map_info *info)
{
	char	*s;

	info->floor_col = 0;
	s = info->floor;
	if (s)
	{
		ft_parse_col(s, &(info->floor_col));
		info->floor_flag = 1;
	}
	else
		ft_close_if_error("Error\ntry to give me floor color baybe\n");
}

void		ft_check_fill_ceiling_col(t_map_info *info)
{
	char	*s;

	info->ceil_col = 0;
	s = info->ceiling;
	if (s)
	{
		ft_parse_col(s, &(info->ceil_col));
		info->ceil_flag = 1;
	}
	else
		ft_close_if_error("Error\nwhere is my ceiling col?\n");
}
