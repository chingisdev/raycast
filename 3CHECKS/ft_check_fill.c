/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvernius <mvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:49:41 by mvernius          #+#    #+#             */
/*   Updated: 2021/03/03 11:27:17 by mvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub3d.h"

static void	ft_run_cycle_res(char *s, int *count, t_map_info *info)
{
	while (ft_isalpha(*s) || ft_isspace(*s))
		s++;
	while (ft_isdigit(*s))
	{
		info->res_width = info->res_width * 10 + (int)(*s - '0');
		s++;
		(*count)++;
	}
	if (*count > 5)
		info->res_width = -1;
	while (ft_isspace(*s))
		s++;
	*count = 0;
	while (ft_isdigit(*s))
	{
		info->res_height = info->res_height * 10 + (int)(*s - '0');
		s++;
		(*count)++;
	}
	if (*count > 5)
		info->res_height = -1;
	if (ft_isalpha(*s) || ft_isspace(*s))
		ft_close_if_error("ERROR: wrong symbols after num\n");
}

void		ft_check_fill_res(t_map_info *info)
{
	int count;

	count = 0;
	info->res_width = 0;
	info->res_height = 0;
	ft_run_cycle_res(info->res, &count, info);
	if (!info->res_height || !info->res_width)
		ft_close_if_error("ERROR: invalid resolution\n");
	info->res_flag = 1;
}

static void	ft_try_open_paths(t_map_info *info)
{
	int	fd;

	fd = open(info->north_path, O_RDONLY);
	if (fd < 0)
		ft_close_if_error("ERROR: wrong path for north textures\n");
	close(fd);
	fd = open(info->south_path, O_RDONLY);
	if (fd < 0)
		ft_close_if_error("ERROR: wrong path for south textures\n");
	close(fd);
	fd = open(info->west_path, O_RDONLY);
	if (fd < 0)
		ft_close_if_error("ERROR: wrong path for west textures\n");
	close(fd);
	fd = open(info->east_path, O_RDONLY);
	if (fd < 0)
		ft_close_if_error("ERROR: wrong path for east textures\n");
	close(fd);
	fd = open(info->spr_path, O_RDONLY);
	if (fd < 0)
		ft_close_if_error("ERROR: wrong path for sprite\n");
	close(fd);
}

void		ft_check_paths(t_map_info *info)
{
	ft_try_open_paths(info);
	if (ft_strncmp(ft_strrchr(
				ft_del_symb_from_end(info->north_path, ' '), '.'), ".xpm", 4))
		ft_close_if_error("ERROR: file format in north path is not .xpm");
	if (ft_strncmp(ft_strrchr(
				ft_del_symb_from_end(info->south_path, ' '), '.'), ".xpm", 4))
		ft_close_if_error("ERROR: file format in south path is not .xpm");
	if (ft_strncmp(ft_strrchr(
				ft_del_symb_from_end(info->west_path, ' '), '.'), ".xpm", 4))
		ft_close_if_error("ERROR: file format in west path is not .xpm");
	if (ft_strncmp(ft_strrchr(
				ft_del_symb_from_end(info->east_path, ' '), '.'), ".xpm", 4))
		ft_close_if_error("ERROR: file format in east path is not .xpm");
	if (ft_strncmp(ft_strrchr(
			ft_del_symb_from_end(info->spr_path, ' '), '.'), ".xpm", 4))
		ft_close_if_error("ERROR: file format in sprite path is not .xpm");
}
