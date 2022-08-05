CC 		= cc
CFLAG	= -Wall -Wextra -Werror
NAME	= so_long
LIBFT	= libft
LIBFT_A = libft.a

SRCS	= so_long.c \
			validator.c \
			verify_map.c \
			init_struct.c \
			render.c \
			event_handler.c \
			event_helper.c \
			utils.c \
			get_next_line/get_next_line_bonus.c \
			get_next_line/get_next_line_utils_bonus.c \

OBJS	= $(SRCS:.c=.o)

all 	: $(NAME)

$(NAME)	: $(OBJS)
			@make all -C $(LIBFT)/
			$(CC) $(LIBFT)/$(LIBFT_A) -o $(NAME) $(OBJS) -L./ -lmlx -framework OpenGL -framework Appkit

%.o	:	%.c
			$(CC) $(CFLAG) -c $< -I./so_long.h -o $@

clean	: 
			rm -f $(OBJS)
			@make clean -C $(LIBFT)

fclean	: clean
			rm -f $(NAME)
			@make fclean -C $(LIBFT)

re		: fclean all

.PHONY	: all clean fclean re
