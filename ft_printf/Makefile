# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 21:28:02 by mingkim           #+#    #+#              #
#    Updated: 2022/04/18 19:34:23 by mingkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME      = libftprintf.a
LIBFT     = libft
LIBFT_LIB = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIBFT_C = ar rc

rm = rm -f

INCS = .

SRCS = ./ft_printf.c \
		./assignment.c \
		./conversion_char.c \
		./conversion_string.c \
		./conversion_int.c \
		./conversion_percent.c \
		./conversion_ptr.c \
		./conversion_hexa.c \
		

OBJS = $(SRCS:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME): $(OBJS)
	@make all -C $(LIBFT)/
	@cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(LIBFT_C) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)
	@make clean -C $(LIBFT)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT)

re: clean all
