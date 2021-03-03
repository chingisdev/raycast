/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvernius <mvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 10:22:32 by mvernius          #+#    #+#             */
/*   Updated: 2021/03/03 10:22:32 by mvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int		ft_arrlen_pos(char **matrix, int pos);
void	ft_bzero(void *destination, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi_modif(char *str, int *num, int *check);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isspace(char c);
int		ft_arrlen(char **matrix);
size_t	ft_strlen(const char *s);
char	*ft_strrchr(const char *s, int c);
char	*ft_generate_str(char c, int quantity);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnjoin_char(char *s1, char s2, int quantity);
char	**ft_split(char const *s, char c);

#endif
