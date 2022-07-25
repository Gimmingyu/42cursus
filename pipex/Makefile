# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 13:55:14 by mingkim           #+#    #+#              #
#    Updated: 2022/07/25 13:05:15 by mingkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
LIBFT = libft
LIBFT_LIB = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

INC = ./pipex.h

SRCS = pipex.c \
		helper.c \

		
OBJS = $(SRCS:.c=.o)

.c.o : 
	$(CC) -c $< -o $(<:.c=.o) -I $(INC)

$(NAME): $(OBJS)
	@make all -C $(LIBFT)/
	$(CC) $(LIBFT)/$(LIBFT_LIB) -o $(NAME) $(OBJS)

all: $(NAME)

clean: 
	$(RM) $(OBJS)
	@make clean -C $(LIBFT)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT)

re: clean all

.PHONY: all clean fclean re
