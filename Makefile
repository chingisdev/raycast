# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvernius <mvernius@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/25 21:49:40 by mvernius          #+#    #+#              #
#    Updated: 2021/03/12 00:43:15 by mvernius         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
NAME			= cub3D
HEADER			= ft_cub3d.h
MLX_LIB_NAME	= libmlx.dylib
DEBUG_DIR		= a.out.dSYM
DEBUG_EXEC		= a.out
MLX_DIR			= mlx
LIB_DIR 		= ./0LIB
LIB_NAME		= libft.a
OPENGL			= -framework OpenGL
APPKIT			= -framework AppKit
#SRC_PATH		= 0LIB 2PARSER 3CHECKS 4DRAWING 5UTILS
#SRC_LIST		= $(wildcard $(dir)/*.c)
#SRC				= $(foreach dir, $(SRC_PATH), $(SRC_LIST))
SRC				= 2PARSER/ft_init_plr_plane.c 2PARSER/ft_parse_col.c 2PARSER/ft_parse_info.c \
					2PARSER/ft_parse_utils.c 2PARSER/ft_parser.c 2PARSER/ft_set_player_dir.c \
					3CHECKS/ft_check_bounds.c 3CHECKS/ft_check_fill.c 3CHECKS/ft_check_input_data.c \
					3CHECKS/ft_check_input_file_extension.c 3CHECKS/ft_surround_whitespace.c \
					4DRAWING/ft_draw_sprites.c 4DRAWING/ft_draw_sprites2.c 4DRAWING/ft_draw_walls.c \
					4DRAWING/ft_draw_walls2.c 4DRAWING/ft_draw.c 4DRAWING/ft_make_bmp.c \
					5UTILS/ft_close_if_error.c 5UTILS/ft_free.c 5UTILS/ft_hook_corresponding.c\
					5UTILS/ft_inits.c 5UTILS/ft_motions.c 5UTILS/ft_my_pixel_put.c\
					5UTILS/ft_puterror.c 5UTILS/ft_rotations.c 5UTILS/main.c \
					5UTILS/ft_atoi_modif.c
PROJ_OBJS		= $(SRC:.c=.o)
RM				= rm
TMP_SWP			= .swp
TMP_GCH			= .gch
SNAPSHOT		= snapshot.bmp
RED				="\033[0;31m"
GREEN			="\033[0;32m"
NC				="\033[0m"

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: makelibft makemlx $(NAME)

makelibft:
		@echo $(GREEN)Making $(LIB_NAME)$(NC)
		@cd $(LIB_DIR) && make
		@echo $(GREEN)$(LIB_NAME) IS CREATED$(NC)

makemlx:
		@echo $(GREEN)Making libmlx.dylib$(NC)
		@cd $(MLX_DIR) && make
		@echo $(GREEN)$(MLX_LIB_NAME) IS CREATED$(NC)
		@cd $(MLX_DIR) && cp $(MLX_LIB_NAME) ../$(MLX_LIB_NAME)
		@echo $(GREEN)$(MLX_LIB_NAME) IS COPIED TO THE PATH OF EXECUTION FILE$(NC)

$(NAME): $(PROJ_OBJS) $(HEADER)
		@$(CC) $(CFLAGS) $(PROJ_OBJS) $(LIB_DIR)/$(LIB_NAME) \
		$(MLX_LIB_NAME) $(OPENGL) $(APPKIT) -o $(NAME)
		@echo $(GREEN)I made it. Check folder and run cub3D $(NC)

clean:
		@echo $(RED)Deleting $(NAME) PROJECT objects $(NC)
		@$(RM) -f $(PROJ_OBJS) $(wildcard *$(TMP_SWP)) $(wildcard *$(TMP_GCH))
		@echo $(RED)Deleted $(NAME) PROJECT objects $(NC)
		@echo $(RED)Deleting $(LIB_NAME) objects $(NC)
		@cd $(LIB_DIR) && make clean
		@echo $(RED)Deleted $(LIB_NAME) objects $(NC)
		@echo $(RED)Deleting $(MLX_LIB_NAME) objects $(NC)
		@cd $(MLX_DIR) && make clean
		@echo $(RED)Deleted $(MLX_LIB_NAME) objects $(NC)
		@echo $(RED)Deleted ALL objects from $(NAME) $(NC)

fclean:	clean
		@echo $(RED)Deleting $(MLX_LIB_NAME)$(NC)
		@$(RM) $(NAME) $(MLX_LIB_NAME)
		@echo $(RED)Deleting $(LIB_NAME)$(NC)
		@cd $(LIB_DIR) && make fclean
		@echo $(RED)Only sources left. $(NC)

re:		fclean all

.PHONY:		all clean fclean re
