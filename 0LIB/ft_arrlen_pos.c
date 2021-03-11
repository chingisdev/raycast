/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrlen_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvernius <mvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 10:23:32 by mvernius          #+#    #+#             */
/*   Updated: 2021/03/11 22:19:49 by mvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_arrlen_pos(char **matrix, int pos)
{
	int	iter;

	iter = 0;
	while (matrix[pos] != NULL)
	{
		iter++;
		pos++;
	}
	return (iter);
}
