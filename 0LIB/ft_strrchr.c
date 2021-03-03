/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvernius <mvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 21:00:44 by mvernius          #+#    #+#             */
/*   Updated: 2021/01/30 20:48:24 by mvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	int		iter;

	ch = c;
	iter = (int)ft_strlen(s);
	while (iter >= 0)
	{
		if (s[iter] == ch)
			return ((char *)(s + iter));
		iter--;
	}
	return (0);
}
