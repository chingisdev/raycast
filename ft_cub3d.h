/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvernius <mvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:13:52 by mvernius          #+#    #+#             */
/*   Updated: 2021/03/03 11:56:44 by mvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D_H
# define FT_CUB3D_H

# include <math.h>
# include "mlx/mlx.h"
# include "0LIB/libft.h"
# include <fcntl.h>

typedef struct	s_win
{
	void	*mlx;
	void	*win;
}				t_win;

typedef struct	s_img
{
	void	*img;
	void	*addr;
	int		line_l;
	int		bpp;
	int		end;
}				t_img;

typedef struct	s_keys
{
	int	frwd;
	int	back;
	int	left;
	int	right;
	int	rl;
	int	rr;
	int	esc;
}				t_keys;

typedef struct	s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}				t_player;

typedef struct	s_sprite
{
	double	x;
	double	y;
	double	dist;
}				t_sprite;

typedef struct	s_map_info
{
	char	*res;
	char	*north_path;
	char	*south_path;
	char	*west_path;
	char	*east_path;
	char	*spr_path;
	char	*floor;
	char	*ceiling;
	short	res_flag;
	short	floor_flag;
	short	ceil_flag;
	int		res_width;
	int		res_height;
	int		floor_col;
	int		ceil_col;
	int		spr_sum;
}				t_map_info;

typedef struct	s_tex
{
	t_img	w_img;
	int		width;
	int		height;
}				t_tex;

typedef struct	s_spr_info
{
	t_img	s_img;
	int		width;
	int		height;
}				t_spr_info;

typedef struct	s_all_tex
{
	t_tex	north;
	t_tex	south;
	t_tex	east;
	t_tex	west;
}				t_all_tex;

typedef struct	s_wall_cast
{
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_x;
	int		tex_height;
	int		tex_y;
	double	camera_x;
	double	ray_x;
	double	ray_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	double	wall_x;
	double	step;
	double	tex_pos;
}				t_wall_cast;

typedef struct	s_sprite_cast
{
	double	sprite_x;
	double	sprite_y;
	double	inv_det;
	double	trans_x;
	double	trans_y;
	int		spr_screen_x;
	int		spr_height;
	int		draw_start_y;
	int		draw_end_y;
	int		spr_width;
	int		draw_start_x;
	int		draw_end_x;
	int		spr_x;
	int		spr_y;
}				t_sprite_cast;

typedef struct	s_all
{
	int				map_size;
	int				*spr_order;
	int				map_start;
	int				max_str_len;
	char			player_dir;
	char			**map;
	double			*z_buf;
	double			*spr_dist;
	t_win			win;
	t_img			*image;
	t_img			tmp_img;
	t_tex			cur_wall;
	t_keys			keys;
	t_player		plr;
	t_sprite		*spr_arr;
	t_map_info		info;
	t_all_tex		textures;
	t_spr_info		sprite;
	t_wall_cast		wall_c;
	t_sprite_cast	spr_c;
}				t_all;

int				ft_close(t_all *all);
int				ft_set_player_dir(char c, t_all *all);
int				ft_close(t_all *all);
int				ft_parser(char *file_name, t_all *all);
int				ft_key_press(int code, t_all *all);
int				ft_event(t_all *all);
int				ft_find_max_len(char **str);
int				ft_key_release(int code, t_all *all);
void			ft_parse_col(char *s, int *color);
void			check_map_lines(char *line);
void			ft_init_plr_plane(t_all *all);
void			ft_check_res_max(t_all *all);
void			ft_raycast(t_all *all);
void			ft_my_free2(int len, char **matrix);
void			ft_wall_casting(t_all *all);
void			ft_draw_walls(t_all *all, int x);
void			draw_stripes2(t_all *all, int stripe, t_spr_info *spr);
void			ft_init_ray_dir(int x, t_all *all);
void			ft_throw_ray(t_all *all);
void			ft_prepare_for_throw(t_all *all);
void			ft_find_perp(t_all *all);
void			ft_find_wall_height(t_all *all);
void			ft_detect_wall_pos(t_all *all);
void			ft_calc_step(t_all *all);
void			ft_prepare_tex(t_all *all);
void			ft_detect_tex_x(t_all *all);
void			ft_detect_texture(t_all *all);
void			ft_make_free(t_all *all);
void			ft_sprite_casting(t_all *all);
void			init_spr_arrays(t_all *all);
void			draw_sprites(t_all *all);
void			make_pos_relative(t_all *all, int i);
void			transform_sprite(t_all *all);
void			prepare_to_draw(t_all *all);
void			ft_prepare_sprites(t_all *all);
void			ft_rotate_right(t_all *all);
void			ft_rotate_left(t_all *all);
void			ft_move_back(t_all *all);
void			ft_move_frwd(t_all *all);
void			ft_move_right(t_all *all);
void			ft_move_left(t_all *all);
void			ft_get_addr(t_all_tex *textures);
void			ft_convert_file_to_image(t_all *all);
void			ft_make_bmp(t_all *all);
void			ft_create_info(t_all *all, int fd);
void			ft_create_header(int fd, int bmp_size);
void			ft_add_spaces_end(t_all *all);
void			ft_check_bounds(char **map, t_all *all);
void			ft_close_if_error(const char *str);
void			ft_puterror(const char *str);
void			ft_pix_put(t_img *img, int x, int y, unsigned int color);
void 			ft_check_file_extension(char *str, char *ext);
void			ft_check_input_data(t_map_info *info);
void			ft_check_fill_res(t_map_info *info);
void			ft_check_fill_floor_col(t_map_info *info);
void			ft_check_fill_ceiling_col(t_map_info *info);
void			ft_check_paths(t_map_info *info);
void			ft_draw_screen(t_all *all);
void			ft_init_all_textures(t_all *all);
void			ft_init_sprite(t_all *all);
void			ft_fill_struct_info(char *str, t_map_info *info);
void			run_checks(t_all *all, char **line, char ***file);
void			ft_check_num_param(t_all *all, char **file);
void			ft_create_map(t_all *all, char **file);
void			ft_swap_sprites(t_all *all, int i, int j);
void			ft_quicksort_spr_arr(t_all *all, int first, int last);
char			*ft_del_symb_from_end(char *str, char symb);
unsigned int	ft_get_color(t_img *img, int x, int y);
char 			*ft_skip_space(char *str);

#endif
