/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input_file_extension.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvernius <mvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 12:49:41 by mvernius          #+#    #+#             */
/*   Updated: 2021/03/03 10:19:33 by mvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_cub3d.h"

void	ft_check_input_file_extension(char *str)
{
	char	*ext;
	char	*file_ext;
	int		fd;

	file_ext = ft_strrchr(str, '.');
	ext = ".cub";
	if (ft_strncmp(ext, file_ext, ft_strlen(ext)))
		ft_close_if_error("ERROR: file extension seems not to be \".cub\"");
	if (*str == '.')
		ft_close_if_error("ERROR: hidden file\n");
	fd = open(str, O_DIRECTORY);
	if (fd > 0)
		ft_close_if_error("ERROR: not a file\n");
	close(fd);
}
