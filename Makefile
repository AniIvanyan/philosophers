NAME = philo

SRCS	= $(wildcard *.c)
OBJS	= $(SRCS:.c=.o)
CC		= cc
CFLAGS	= -pthread #-Wall -Wextra -Werror
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