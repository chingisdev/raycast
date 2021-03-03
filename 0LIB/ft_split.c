/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvernius <mvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 10:23:53 by mvernius          #+#    #+#             */
/*   Updated: 2021/03/03 10:24:12 by mvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		len_cur_word(char const *s, char c)
{
	int		length;

	length = 0;
	while (*s && *s != c)
	{
		length++;
		s++;
	}
	return (length);
}

static size_t	count_words(char const *s, char c)
{
	int		state;
	size_t	count;

	state = 0;
	count = 0;
	while (*s)
	{
		if (*s == c && state == 1)
			state = 0;
		if (*s != c && state == 0)
		{
			count++;
			state = 1;
		}
		s++;
	}
	return (count);
}

static void		*my_free(char **array, size_t i)
{
	while (i-- >= 0)
		free(array[i]);
	free(array);
	return (NULL);
}

static size_t	create_str(const char *s, char c, char **arr, size_t *iter)
{
	int	len_word;
	int	i;

	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			len_word = len_cur_word(s, c);
			arr[*iter] = (char *)malloc(len_word + 1);
			if (NULL == arr[*iter])
				return (1);
			i = 0;
			while (i < len_word && *s)
				arr[*iter][i++] = *s++;
			arr[(*iter)++][i] = '\0';
		}
	}
	return (0);
}

char			**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	iter;

	if (!s)
		return (NULL);
	iter = 0;
	arr = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (NULL == arr)
		return (NULL);
	if (create_str(s, c, arr, &iter))
		return (my_free(arr, iter));
	arr[iter] = NULL;
	return (arr);
}
