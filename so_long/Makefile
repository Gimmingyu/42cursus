CC 		= cc
CFLAG	= -Wall -Wextra -Werror
NAME	= so_long

SRCS	= so_long.c 
OBJS	= $(SRCS:.c=.o)

all 	: $(NAME)

$(NAME)	: $(OBJS)
			$(CC) -o $(NAME) $(OBJS) -L./ -lmlx -framework OpenGL -framework Appkit

%.o		: %.c
			$(CC) $(CFLAG) -c $< -I./ -o $@

clean	: 
			rm -f $(OBJS)

fclean	: clean
			rm -f $(NAME)

re		: fclean all

.PHONY	: all clean fclean re
