# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kimmingyu <kimmingyu@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 13:55:14 by mingkim           #+#    #+#              #
#    Updated: 2022/07/19 22:04:31 by kimmingyu        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT = libft
LIBFT_LIB = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

INC = ./push_swap.h

SRCS = push_swap.c \
		exception_handler.c \
		helper.c \
		info.c \
		main.c \
		opt_case.c \
		optimization.c \
		push.c \
		reverse.c \
		reversed_opt_case.c \
		reversed_optimization.c \
		rotate.c \
		solution.c \
		solution_utils.c \
		stack.c \
		swap.c \
		utils.c \
		validator.c \
		
OBJ_DIR = ./
OBJS = $(SRCS:.c=.o)

.c.o : 
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INC)

$(NAME): $(OBJS)
	@make all -C $(LIBFT)/
	$(CC) $(CFLAGS) $(LIBFT)/$(LIBFT_LIB) -o $(NAME) $(OBJS)

all: $(NAME)

clean: 
	$(RM) $(OBJS)
	@make clean -C $(LIBFT)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT)

re: clean all

.PHONY: all clean fclean re
