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

SOURCES		= $(shell find . -type f -name '*.c' -and -not -name 'ft_lst*.c')

OBJECTS		= $(patsubst %.c,%.o,$(SOURCES))

BON_SOURCES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			  ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			  ft_lstmap.c 

BON_OBJECTS	= $(patsubst %.c,%.o,$(BON_SOURCES))

.c.o:
			@$(CC) $(CFLAGS) -I. -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJECTS)
			@$(AR) $(NAME) $(OBJECTS)

bonus:		$(BON_OBJECTS) all
			@$(AR) $(NAME) $(OBJECTS) $(BON_OBJECTS)

clean:
			@$(RM) $(OBJECTS) $(TMPFILE) $(BON_OBJECTS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean bonus re
