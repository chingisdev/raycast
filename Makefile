# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvernius <mvernius@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/25 21:49:40 by mvernius          #+#    #+#              #
#    Updated: 2021/03/03 12:28:49 by mvernius         ###   ########.fr        #
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
SRC_PATH		= 0LIB 2PARSER 3CHECKS 4DRAWING 5UTILS
SRC_LIST		= $(wildcard $(dir)/*.c)
SRC				= $(foreach dir, $(SRC_PATH), $(SRC_LIST))
PROJ_OBJS		= $(SRC:.c=.o)
RM				= rm
TMP_SWP			= .swp
TMP_GCH			= .gch
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
