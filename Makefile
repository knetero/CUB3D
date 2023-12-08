CC = cc
FLAGS = -g -Wall -Wextra -Werror

SRCS = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c parsing.c utils.c parsing_utils.c cub3d.c 
OBJS = $(SRCS:.c=.o)
NAME = CUB3D
HEADERS = cub3d.h get_next_line/get_next_line.h
all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(CC) $(FLAGS) $(OBJS) libmlx42.a -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -o $@

%.o: %.c $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f  $(OBJS)

fclean: clean
	rm -f  $(NAME)

re: fclean all