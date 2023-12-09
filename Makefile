CC = cc
FLAGS = -g -Wall -Wextra -Werror

SRCS = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c parsing/parsing.c cub_utils/utils.c cub_utils/parsing_utils.c cub3d.c \
		cub_utils/path_parsing_utils.c parsing/rgb_parsing.c parsing/path_parsing.c cub_utils/map_utils.c \
		Libft/ft_split.c Libft/ft_atoi.c Libft/ft_isdigit.c \
		graphics/put_pixels.c

OBJS = $(SRCS:.c=.o)
NAME = CUB3D
HEADERS = includes/cub3d.h get_next_line/get_next_line.h Libft/libft.h


all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(CC) $(FLAGS) $(OBJS) includes/libmlx42.a -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -o $@

%.o: %.c $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f  $(OBJS)

fclean: clean
	rm -f  $(NAME)

re: fclean all