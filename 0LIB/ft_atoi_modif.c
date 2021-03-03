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

#include "libft.h"

int	ft_atoi_modif(char *str, int *num, int *check)
{
	int	iter;
	int	sign;
	int	flag;

	flag = -2;
	*num = 0;
	sign = 1;
	iter = -1;
	while (str[++iter] && !(ft_isdigit(str[iter]))
		&& str[iter] != '-' && str[iter] != '\n')
		;
	if (str[iter] == '-' || str[iter] == '+')
	{
		if (str[iter++] == '-')
			sign *= -1;
	}
	while (ft_isdigit(str[iter]))
	{
		flag = 1;
		*num = *num * 10 + (str[iter++] - '0');
	}
	*num *= sign;
	if (flag == 1)
		*check += 1;
	return (iter);
}
