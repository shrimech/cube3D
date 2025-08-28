# -------Variables----------

NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT_DIR = ./src/libft
GNL_DIR = ./src/gnl
LIBFT = $(LIBFT_DIR)/libft.a
GNL = $(GNL_DIR)/gnl.a

# -----Source directories------ \

PARSE = build_map.c  parse_map.c  read_map.c

TEST = ./test

# -------source files----------

MAIN_SRCS = freefire.c

SRCS = $(PARSE) $(MAIN_SRCS)

# -------Object files----------

OBJS = $(SRCS:.c=.o)

# -------Header dependencies----------
INCLUDES = -I ../includes -I $(LIBFT_DIR) -I $(GNL_DIR)

# -------Rules----------
all: $(LIBFT) $(GNL) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(READLINE_FLAGS) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(GNL):
	make -C $(GNL_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(GNL_DIR) clean

fclean:
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(GNL_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
