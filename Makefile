# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aivanyan <aivanyan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 18:09:48 by aivanyan          #+#    #+#              #
#    Updated: 2023/01/25 18:09:51 by aivanyan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS	= $(wildcard *.c)
OBJS	= $(SRCS:.c=.o)
CC		= cc
CFLAGS	= -pthread -Wall -Wextra -Werror 
RM		= rm -f

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all
