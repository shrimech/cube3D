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
ENGINE_CORE_DIR = $(ENGINE_DIR)/core
ENGINE_PHYSICS_DIR = $(ENGINE_DIR)/physics
ENGINE_RASTERIZER_DIR = $(ENGINE_DIR)/rasterizer
PARSE_DIR = ./src/parse
MISC_DIR = ./src/misc

#-------MLX Setup
MLX_PATH = ./includes/minilibx-linux
MLX_FLAGS = -L$(MLX_PATH) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

# -------Header dependencies----------
INCLUDES = -I ./includes -I $(LIBFT_DIR) -I $(GNL_DIR) -I $(MLX_PATH)

# -----Source files----- 


PARSE = $(PARSE_DIR)/build_map.c \
		$(PARSE_DIR)/parse_hole_map.c \
		$(PARSE_DIR)/parse_map.c \
		$(PARSE_DIR)/read_map.c \
		$(PARSE_DIR)/checkers.c \
		$(PARSE_DIR)/map_helpers.c

ENGINE_CORE =		$(ENGINE_CORE_DIR)/boot.c
EMGINE_PHYSICS =	$(ENGINE_PHYSICS_DIR)/motion.c
ENGINE_RASTERIZER =	$(ENGINE_RASTERIZER_DIR)/frame_flush.c \
					$(ENGINE_RASTERIZER_DIR)/soft_raster.c \
					$(ENGINE_RASTERIZER_DIR)/geometry.c \
					$(ENGINE_RASTERIZER_DIR)/raycasting.c

ENGINE = $(ENGINE_CORE) $(EMGINE_PHYSICS)  $(ENGINE_RASTERIZER)

GNL = $(GNL_DIR)/get_next_line.c\
	  $(GNL_DIR)/get_next_line_utils.c

MISC =	$(MISC_DIR)/error.c \
		$(MISC_DIR)/exit.c \
		$(MISC_DIR)/helpers.c \
		$(MISC_DIR)/memory.c

TEST = $(PARSE_DIR)/debug.c

# -------Main----------

MAIN_SRCS = freefire.c

SRCS = $(GNL) $(PARSE) $(MAIN_SRCS) $(TEST) $(MISC) $(ENGINE)

# -------Object files----------

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_PATH)/libmlx.a $(MLX_FLAGS) -o $(NAME)

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

