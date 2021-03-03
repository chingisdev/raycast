/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvernius <mvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 12:18:29 by mvernius          #+#    #+#             */
/*   Updated: 2021/01/28 12:21:18 by mvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin_char(char *s1, char c, int quantity)
{
	char	*result;
	size_t	len;
	int		i;

	if (!s1)
		s1 = ft_strdup("");
	i = 0;
	len = ft_strlen(s1) + quantity + 1;
	result = (char *)malloc(len * sizeof(char));
	if (NULL == result)
		return (NULL);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (quantity--)
		result[i++] = c;
	result[i] = '\0';
	free(s1);
	return (result);
}
