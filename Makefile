NAME		=	fdf
FLAGS		=	-Wall -Werror -Wextra
MLX			=	-lmlx -lXext -lX11 -lm
LIBS		=	-L ./tools/libft -lft -L /usr/local/lib
INCLUDES	=	-I ./tools/libft -I ./libfdf -I ./parsing/get_next_line -I /usr/local/include
SRCS		=	parsing/ft_init.c\
			parsing/ft_param.c\
			parsing/ft_free.c\
			parsing/ft_check_file_name.c\
			print/print_struct.c\
			parsing/get_next_line/get_next_line.c\
			parsing/get_next_line/get_next_line_utils.c\
			main.c
OBJS		= 	$(SRCS:.c=.o)

%.o: %.c
	gcc $(FLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

all: make-libft $(NAME)

make-libft:
	make -C tools/libft/

$(NAME) : $(OBJS)
	gcc $(FLAGS) $(INCLUDES) $(OBJS) $(LIBS) $(MLX) -o $(NAME)

	
clean:
			make -C tools/libft clean
			rm -f $(OBJS)

fclean:
			make -C tools/libft fclean
			rm -f $(OBJS)
			rm -f $(NAME)

re:			fclean all
