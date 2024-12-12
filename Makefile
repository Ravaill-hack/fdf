NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBMLX = -L ./minilibx-linux -lmlx -lXext -lX11

SRCS_FILES =  \
	main.c

OBJS = $(SRCS_FILES:.c=.o)

all: $(NAME)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBMLX) 

%.o: %.c
	$(CC) $(CFLAGS) -I ./minilibx-linux -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
