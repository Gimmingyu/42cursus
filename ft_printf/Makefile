# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mingkim <mingkim@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 21:28:02 by mingkim           #+#    #+#              #
#    Updated: 2022/03/21 19:06:04 by mingkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME      = libftprintf.a
LIBFT     = libft
LIBFT_LIB = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

AR = ar -rcs

rm = rm -f

INCS = ./

SRCS = ./ft_printf.c

OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME): $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB)/ $(NAME)
	$(AR) $@ $?

all: $(NAME)

clean:
	$(RM) $(OBJS) $(B_OBJS)
	make clean -C $(LIBFT)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

re: clean all

.PHONY: all clean fclean re libft
