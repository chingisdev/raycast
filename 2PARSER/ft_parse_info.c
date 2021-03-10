/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvernius <mvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 18:36:21 by mvernius          #+#    #+#             */
/*   Updated: 2021/03/10 16:27:59 by mvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub3d.h"

void	ft_fill_struct_info(char *str, t_map_info *info)
{
	if (!(ft_strncmp(str, "R ", ft_strlen("R "))) && !(info->res_flag))
		info->res = ft_strjoin("", ft_skip_space(str + 1));
	else if (!(ft_strncmp(str, "NO ", ft_strlen("NO "))))
		info->north_path = ft_strjoin("", ft_skip_space(str + 2));
	else if (!(ft_strncmp(str, "SO ", ft_strlen("SO "))))
		info->south_path = ft_strjoin("", ft_skip_space(str + 2));
	else if (!(ft_strncmp(str, "WE ", ft_strlen("WE "))))
		info->west_path = ft_strjoin("", ft_skip_space(str + 2));
	else if (!(ft_strncmp(str, "EA ", ft_strlen("EA "))))
		info->east_path = ft_strjoin("", ft_skip_space(str + 2));
	else if (!(ft_strncmp(str, "S ", ft_strlen("S "))))
		info->spr_path = ft_strjoin("", ft_skip_space(str + 1));
	else if (!(ft_strncmp(str, "F ", ft_strlen("F "))) && !(info->floor_flag))
		info->floor = ft_strjoin("", ft_skip_space(str + 1));
	else if (!(ft_strncmp(str, "C ", ft_strlen("C "))) && !(info->ceil_flag))
		info->ceiling = ft_strjoin("", ft_skip_space(str + 1));
	else
		ft_close_if_error("Error\nwrong value (line) in map.cub\n");
}

void	check_map_lines(char *line)
{
	int	pseudo_param;
	int i;

	i = 0;
	pseudo_param = 0;
	while (line[i + 1] && pseudo_param < 8)
	{
		if (line[i] != '\n' && line[i + 1] == '\n')
			pseudo_param += 1;
		i++;
	}
	while (line[i] == '\n')
		i++;
	while (line[i + 1])
	{
		if (line[i] == '\n' && line[i + 1] == '\n')
			ft_close_if_error("Error\nwhite lines in map\n");
		i++;
	}
}
