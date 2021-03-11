CFLAGS		= -Wall -Wextra -Werror
SOURCEDIR	= srcs
HDR			= libft.h
CC			= gcc
NAME		= libft.a
RM			= rm -rf
TMPFILE		= .swp
AR			= ar rcs
RED			="\033[0;31m"
GREEN		="\033[0;32m"
NC			="\033[0m"

#SOURCES		= $(shell find . -type f -name '*.c' -and -not -name 'ft_lst*.c')
SOURCES		= ft_arrlen_pos.c ft_arrlen.c \
				ft_bzero.c ft_generate_str.c ft_isalpha.c \
				ft_isdigit.c ft_isspace.c ft_memcpy.c \
				ft_split.c ft_strdup.c ft_strjoin.c \
				ft_strlen.c ft_strncmp.c ft_strnjoin_char.c \
				ft_strrchr.c

OBJECTS		= $(patsubst %.c,%.o,$(SOURCES))

.c.o:
			@$(CC) $(CFLAGS) -I. -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJECTS)
			@$(AR) $(NAME) $(OBJECTS)

clean:
			@$(RM) $(OBJECTS) $(TMPFILE) $(BON_OBJECTS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
