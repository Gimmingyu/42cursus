# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mingkim <mingkim@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 13:55:14 by mingkim           #+#    #+#              #
#    Updated: 2022/07/19 22:04:31 by mingkim        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
RM = rm -f

INC = ./philo.h

SRCS = philo.c \
		init_struct.c \
		utils.c \
		status.c \
		act.c \

OBJS = $(SRCS:.c=.o)

.c.o : 
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INC)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
