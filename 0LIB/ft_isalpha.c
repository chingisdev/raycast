/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvernius <mvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 17:15:54 by mvernius          #+#    #+#             */
/*   Updated: 2021/03/03 10:22:55 by mvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_islower(int c)
{
	unsigned char	ch;
	int				res;

	res = 0;
	ch = c;
	if (c >= 'a' && c <= 'z')
		res = 1;
	return (res);
}

static	int	ft_isupper(int c)
{
	unsigned char	ch;
	int				res;

	res = 0;
	ch = c;
	if (c >= 'A' && c <= 'Z')
		res = 1;
	return (res);
}

int			ft_isalpha(int c)
{
	int					res;

	res = 0;
	if (ft_islower(c) || ft_isupper(c))
		res = 1;
	return (res);
}
