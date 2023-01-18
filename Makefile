SRCS		= main.c check.c drawing.c events.c free.c get_data_utils.c get_data.c get_next_line_utils.c
SRCS		+= get_next_line.c mlx_events.c preprocessing.c process.c raycast.c utils.c
RM			= rm -f
GCC			= gcc -Wall -Wextra -Werror
NAME		= cub3D

all: $(NAME)

$(NAME): $(SRCS) cub3D.h Makefile
	@make -C ./libft
	@make -C ./mlx
	$(GCC) -I./mlx -framework OpenGL -framework AppKit libft/libft.a $(SRCS) -L./mlx -lmlx -o $(NAME)

clean:
	$(RM) $(NAME)

fclean:	clean
	@make -C ./libft fclean
	@make -C ./mlx clean
	@echo "cleaning 100%"

re:	fclean
	make

.PHONY:			all clean fclean re
