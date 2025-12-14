# -------Variables----------
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# -------executables and libs----------
NAME = cub3D
LIBFT = $(LIBFT_DIR)/libft.a


# -------Directories----------
LIBFT_DIR = ./src/libft
GNL_DIR = ./src/gnl
ENGINE_DIR = ./src/engine
PARSE_DIR = ./src/parse
MISC_DIR = ./src/misc

#-------MLX Setup
MLX_PATH = /usr/include/minilibx-linux
MLX_FLAGS = -L$(MLX_PATH) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

# -------Header dependencies----------
INCLUDES = -I ./includes -I $(LIBFT_DIR) -I $(GNL_DIR) -I $(MLX_PATH)

# -----Source files----- 

ENGINE = $(ENGINE_DIR)/init_game.c

PARSE = $(PARSE_DIR)/build_map.c \
		$(PARSE_DIR)/parse_hole_map.c \
		$(PARSE_DIR)/parse_map.c \
		$(PARSE_DIR)/read_map.c \
		$(PARSE_DIR)/map_helpers.c

GNL = $(GNL_DIR)/get_next_line.c\
	  $(GNL_DIR)/get_next_line_utils.c

MISC =	$(MISC_DIR)/error.c \
		$(MISC_DIR)/exit.c

TEST = $(PARSE_DIR)/debug.c

# -------Main----------

MAIN_SRCS = freefire.c

SRCS = $(GNL) $(PARSE) $(MAIN_SRCS) $(TEST) $(MISC) $(ENGINE)

# -------Object files----------

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

