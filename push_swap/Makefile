# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 13:55:14 by mingkim           #+#    #+#              #
#    Updated: 2022/07/08 13:30:04 by mingkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
LIBFT = libft
LIBFT_LIB = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

INC = include/push_swap.h

SRC_DIR = src/
SRCS = src/push_swap.c \
		src/utils.c \
		src/exception_handler.c \
		src/validator.c \
		src/commands/push.c \
		src/commands/swap.c \
		
OBJ_DIR = ./src/
OBJS = $(SRCS:.c=.o)

.c.o : 
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INC)

$(NAME): $(OBJS)
	@make all -C $(LIBFT)/
	@cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean: 
	$(RM) $(OBJS)
	@make clean -C $(LIBFT)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT)

re: clean all



