/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvernius <mvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 12:49:00 by mvernius          #+#    #+#             */
/*   Updated: 2021/02/26 01:12:39 by mvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub3d.h"

void	ft_check_input_data(t_map_info *info)
{
	ft_check_fill_res(info);
	ft_check_fill_floor_col(info);
	ft_check_fill_ceiling_col(info);
	ft_check_paths(info);
}
