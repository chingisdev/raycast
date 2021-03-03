/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvernius <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:52:07 by mvernius          #+#    #+#             */
/*   Updated: 2020/11/06 16:08:15 by mvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*dst;

	len = ft_strlen(s1);
	dst = (char *)malloc((len + 1) * sizeof(char));
	if (NULL == dst)
		return (NULL);
	dst = ft_memcpy(dst, s1, len);
	dst[len] = '\0';
	return (dst);
}
