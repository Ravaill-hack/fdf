NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./Includes/libft

LIBFT = -L $(LIBFT_DIR) -lft

LIBMLX = -L ./Includes/minilibx-linux -lmlx -lXext -lX11

SRCS_DIR = Src

OBJS_DIR = Obj

SRCS_FILES =  \
	$(SRCS_DIR)/main.c

OBJS = $(SRCS_FILES:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBMLX) $(LIBFT)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -I ./Includes/minilibx-linux -c $< -o $@

clean:
	rm -f $(OBJS)
	@$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
