/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvernius <mvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:49:41 by mvernius          #+#    #+#             */
/*   Updated: 2021/03/10 16:28:54 by mvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub3d.h"

static void	ft_run_cycle_res(char *s, int *count, t_map_info *info)
{
	while (*s == '0')
		s++;
	while (ft_isdigit(*s))
	{
		info->res_width = info->res_width * 10 + (int)(*s - '0');
		s++;
		(*count)++;
	}
	if (*count > 5)
		info->res_width = -1;
	while (ft_isspace(*s) || *s == '0')
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
	if (*s != '\0')
		ft_close_if_error("Error\nwrong symbols in resolution\n");
}

void		ft_check_fill_res(t_map_info *info)
{
	int count;

	count = 0;
	info->res_width = 0;
	info->res_height = 0;

	ft_run_cycle_res(info->res, &count, info);
	if (!info->res_height || !info->res_width)
		ft_close_if_error("Error\ninvalid resolution\n");
	info->res_flag = 1;
}

char *ft_skip_space(char *str)
{
	char *copy;

	copy = str;
	while (ft_isspace(*copy))
		copy++;
	return (copy);
}
void 		ft_check_paths(t_map_info *info)
{
	ft_check_file_extension(info->north_path, ".xpm");
	ft_check_file_extension(info->west_path, ".xpm");
	ft_check_file_extension(info->south_path, ".xpm");
	ft_check_file_extension(info->east_path, ".xpm");
	ft_check_file_extension(info->spr_path, ".xpm");
}
