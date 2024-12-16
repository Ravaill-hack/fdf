NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./Includes/libft

LIBMLX_DIR = ./Includes/minilibx-linux

LIBFT = -L $(LIBFT_DIR) -lft

LIBMLX = -L $(LIBMLX_DIR) -lmlx -lXext -lX11

SRCS_DIR = Src

OBJS_DIR = Obj

SRCS_FILES =  \
	$(SRCS_DIR)/main.c \
	$(SRCS_DIR)/line_utils.c \
	$(SRCS_DIR)/free_utils.c \
	$(SRCS_DIR)/init.c \
	$(SRCS_DIR)/events.c \
	$(SRCS_DIR)/parsing.c \
	$(SRCS_DIR)/utils.c

OBJS = $(SRCS_FILES:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBMLX) $(LIBFT)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -I $(LIBMLX_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	@$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
