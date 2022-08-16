# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/16 16:14:53 by mingkim           #+#    #+#              #
#    Updated: 2022/08/16 16:36:18 by mingkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

INC = ./philo.h

SRCS = philo.c \
		utils.c \
		validator.c \
		init_struct.c \
		status.c \ 

		
OBJS = $(SRCS:.c=.o)

.c.o : 
	$(CC) -c $< -o $(<:.c=.o) -I $(INC)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

all: $(NAME)

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
