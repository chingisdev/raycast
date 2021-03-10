/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvernius <mvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 18:33:52 by mvernius          #+#    #+#             */
/*   Updated: 2021/03/10 16:28:25 by mvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub3d.h"

void	ft_check_res_max(t_all *all)
{
	int	x;
	int	y;

	mlx_get_screen_size(all->win.mlx, &x, &y);
	if (all->info.res_width > x || all->info.res_width == -1)
	{
		all->info.res_width = x;
	}
	if (all->info.res_height > y || all->info.res_height == -1)
	{
		all->info.res_height = y;
	}
}

int		ft_get_param_num(char **map, t_all *all)
{
	int	param;
	int	i;

	i = 0;
	param = 0;
	while (map[i][0] != '1' && map[i][0] != ' ')
	{
		if (map[i][0] != '\0')
		{
			ft_fill_struct_info(map[i], &(all->info));
			param++;
		}
		i++;
	}
	all->map_start = i;
	return (param);
}

void	ft_check_num_param(t_all *all, char **file)
{
	int	param;

	param = 0;
	param = ft_get_param_num(file, all);
	if (param != 8)
	{
		ft_my_free2(ft_arrlen(file), file);
		ft_close_if_error("Error\nwrong number of parameters are given\n");
	}
	ft_check_input_data(&(all->info));
}

void	ft_create_map(t_all *all, char **file)
{
	int		i;
	int		pos;
	int		arlen;
	char	**map;

	all->map = NULL;
	pos = all->map_start;
	arlen = ft_arrlen_pos(file, pos);
	map = (char **)malloc((arlen + 3) * sizeof(char *));
	if (NULL == map)
		ft_close_if_error("Error\nallocation problem in func \"fill_map\"\n");
	all->max_str_len = ft_find_max_len(file);
	map[0] = ft_generate_str(' ', all->max_str_len);
	i = 1;
	while (file[pos])
	{
		map[i] = ft_strdup(file[pos]);
		i++;
		pos++;
	}
	map[i++] = ft_generate_str(' ', all->max_str_len);
	all->map_size = i;
	map[i] = NULL;
	all->map = map;
}

int		ft_parser(char *file_name, t_all *all)
{
	int		fd;
	char	buf;
	char	*line;
	char	**file;

	line = NULL;
	ft_check_file_extension(file_name, ".cub");
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		ft_close_if_error("Error\ncan not open file in func \"parser\"");
	while ((read(fd, &buf, 1)) > 0)
		line = ft_strnjoin_char(line, buf, 1);
	check_map_lines(line);
	file = ft_split(line, '\n');
	if (NULL == file)
	{
		free(line);
		ft_close_if_error("Error\ncan't split\n");
	}
	run_checks(all, &line, &file);
	return (0);
}
