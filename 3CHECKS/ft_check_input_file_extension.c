/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file_extension.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvernius <mvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 12:49:41 by mvernius          #+#    #+#             */
/*   Updated: 2021/03/09 23:07:43 by mvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub3d.h"

void ft_check_file_extension(char *str, char *ext)
{
	char	*file_ext;
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		ft_close_if_error("ERROR: can't open file\n");
	file_ext = ft_strrchr(str, '.');
	if (ft_strncmp(ext, file_ext, ft_strlen(ext)))
		ft_close_if_error("ERROR: file extension is not correct");
	fd = open(str, O_DIRECTORY);
	if (fd > 0)
		ft_close_if_error("ERROR: not a file\n");
	if (*str == '.' && (ft_strlen(str) == ft_strlen(ext)))
		ft_close_if_error("ERROR: hidden file\n");
	if (ft_strlen(str) > ft_strlen(file_ext))
	{
		file_ext--;
		if (!(ft_isalpha(*file_ext) || ft_isdigit(*file_ext)))
			ft_close_if_error("ERROR: hidden file\n");
	}
	close(fd);
}
