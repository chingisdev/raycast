/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvernius <mvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:39:22 by mvernius          #+#    #+#             */
/*   Updated: 2021/03/03 10:23:09 by mvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_generate_str(char c, int quantity)
{
	char	*result;
	int		i;

	i = 0;
	result = (char *)malloc((quantity + 1) * sizeof(char));
	if (NULL == result)
		return (NULL);
	while (quantity--)
		result[i++] = c;
	result[i] = '\0';
	return (result);
}
