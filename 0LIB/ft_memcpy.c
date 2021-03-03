/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvernius <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:06:05 by mvernius          #+#    #+#             */
/*   Updated: 2020/11/12 16:03:16 by mvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp;

	if (dst != src && n)
	{
		tmp = (unsigned char *)dst;
		while (n--)
			*tmp++ = *(unsigned char *)src++;
	}
	return (dst);
}
