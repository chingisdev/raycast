/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_surround_whitespace.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvernius <mvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:29:00 by mvernius          #+#    #+#             */
/*   Updated: 2021/03/03 11:29:02 by mvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub3d.h"

int		ft_find_max_len(char **str)
{
	int	max_len;
	int	str_len;

	max_len = 0;
	while (*str)
	{
		str_len = ft_strlen(*str++);
		if (str_len > max_len)
			max_len = str_len;
	}
	return (max_len);
}

void	ft_add_spaces_end(t_all *all)
{
	int		max_len;
	int		str_len;
	int		t;
	char	**str;
	char	*tmp;

	str = all->map;
	max_len = all->max_str_len;
	t = 0;
	while (str[t])
	{
		str_len = ft_strlen(str[t]);
		str[t] = ft_strnjoin_char(str[t], ' ', (max_len + 1 - str_len));
		tmp = str[t];
		str[t] = ft_strjoin(" ", tmp);
		free(tmp);
		t++;
	}
}
