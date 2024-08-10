NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=thread 

SRC = $(wildcard *.c) $(wildcard ./helpers/*.c)

SRCO = $(SRC:.c=.o)

all:$(NAME)

${NAME}: ${SRCO} 
	@$(CC) $(CFLAGS) $(SRCO) $(MLX) -o $(NAME)

clean:
	-rm -rf $(SRCO)
fclean: clean
	-rm -rf $(SRCO) $(NAME)

re: fclean all

.PHONY: all clean fclean re