# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mingkim <mingkim@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 19:38:36 by mingkim           #+#    #+#              #
#    Updated: 2022/07/23 12:12:56 by mingkim        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

INCLUDES = ./libft.h

FILES = ft_split \
		ft_strlcpy \
		ft_strlen \
		ft_strlcat \
		ft_strncmp \
		ft_strjoin \
		ft_strdup \
		ft_itoa \
		
		
SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

%.o : %.c
	$(CC) $(CLFAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $@ $?

all: $(NAME)

clean:
	$(RM) $(OBJS) $(B_OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
