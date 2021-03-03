/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_symb_from_end.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvernius <mvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 18:05:55 by mvernius          #+#    #+#             */
/*   Updated: 2021/02/26 01:44:26 by mvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub3d.h"

char	*ft_del_symb_from_end(char *str, char symb)
{
	int		len;

	len = ft_strlen(str);
	--len;
	while (str[len] == symb)
		str[len--] = '\0';
	return (str);
}
