/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_modif.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvernius <mvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 18:29:44 by mvernius          #+#    #+#             */
/*   Updated: 2021/02/26 00:27:03 by mvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub3d.h"

int	ft_atoi_modif(char *str, int *num, int *check)
{
	int	iter;
	int	flag;

	flag = -2;
	*num = 0;
	iter = 0;
	while (ft_isspace(str[iter]))
		iter++;
	if (str[iter] == ',')
		iter++;
	while (ft_isspace(str[iter]))
		iter++;
	while (ft_isdigit(str[iter]))
	{
		flag = 1;
		*num = *num * 10 + (str[iter++] - '0');
		if (*num > 255)
			ft_close_if_error("Error\nwrong number value\n");
	}
	if (flag == 1)
		*check += 1;
	return (iter);
}
