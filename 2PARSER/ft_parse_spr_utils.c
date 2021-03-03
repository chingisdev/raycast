/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_spr_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvernius <mvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 00:32:59 by mvernius          #+#    #+#             */
/*   Updated: 2021/03/03 10:54:47 by mvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub3d.h"

static void	ft_init_info_struct(t_map_info *info)
{
	info->ceiling = NULL;
	info->res = NULL;
	info->north_path = NULL;
	info->south_path = NULL;
	info->west_path = NULL;
	info->east_path = NULL;
	info->spr_path = NULL;
	info->floor = NULL;
	info->res_width = -1;
	info->res_height = -1;
	info->floor_col = -1;
	info->ceil_col = -1;
	info->res_flag = 0;
	info->floor_flag = 0;
	info->ceil_flag = 0;
	info->spr_sum = 0;
}

static void	ft_count_sprites(char **map, int *sprites_sum)
{
	int	i;
	int	j;

	i = 0;
	*sprites_sum = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '2')
			{
				(*sprites_sum)++;
			}
			j++;
		}
		i++;
	}
}

static void	ft_add_sprites_to_arr(char **map, t_sprite **spr_arr)
{
	int	x;
	int	y;
	int	z;

	z = 0;
	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == '2')
			{
				(*spr_arr)[z].x = x + 0.5;
				(*spr_arr)[z].y = y + 0.5;
				z++;
			}
			y++;
		}
		x++;
	}
}

void		ft_prepare_sprites(t_all *all)
{
	all->spr_arr = NULL;
	ft_count_sprites(all->map, &(all->info.spr_sum));
	all->spr_arr = (t_sprite *)malloc((all->info.spr_sum)
			* sizeof(t_sprite));
	if (NULL == all->spr_arr)
		ft_close_if_error("ERROR: malloc in ft_parser");
	ft_add_sprites_to_arr(all->map, &(all->spr_arr));
	all->spr_order = (int *)malloc(all->info.spr_sum * sizeof(int));
	if (NULL == all->spr_order)
		ft_close_if_error("ERROR: allocating spr_order\n");
	all->spr_dist = (double *)malloc(all->info.spr_sum * sizeof(double));
	if (NULL == all->spr_dist)
		ft_close_if_error("ERROR: allocating spr_dist\n");
}

void		run_checks(t_all *all, char **line, char ***file)
{
	ft_init_info_struct(&(all->info));
	ft_check_num_param(all, *file);
	ft_create_map(all, *file);
	ft_add_spaces_end(all);
	ft_check_bounds(all->map, all);
	ft_prepare_sprites(all);
	ft_check_res_max(all);
	ft_my_free2(ft_arrlen(*file), *file);
	free(*line);
}
