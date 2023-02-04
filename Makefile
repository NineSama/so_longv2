NAME =		so_long

SRCS_DIR = srcs/

GNL_DIR = GNL/

SRCS =		main.c \
			get_next_line.c \
			parsing.c \
			map_to_win.c \
			valid.c \
			utils.c \
			init.c \
			move.c \
			end.c \
			free.c \
			pathfinding.c

_DEPS =		so_long.h

INCL =		./includes/


OBJS =		${SRCS:.c=.o}

CC =		clang

RM =		rm -f

CFLAGS =	-Wall -Werror -Wextra -g

MLX =		./mlx

MLX_LIB = 	./mlx/libmlx.a

.c.o:
		${CC} ${CFLAGS} -I${INCL} -I${MLX} -g3 -c $< -o ${<:.c=.o}

$(NAME):	${OBJS} $(MLX_LIB)
		${CC} ${CFLAGS}  ${OBJS} -o ${NAME} ${MLX_LIB}\
		-L -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

$(MLX_LIB):
		make -C ${MLX} -j


all:		${NAME}

clean:		
		${RM} ${OBJS}
		make clean -C ${MLX}

fclean:		clean
		${RM} ${NAME}
		${RM} ${NAME} ${MLX_LIB}

re:		fclean
		$(MAKE) all -j

.PHONY:		all clean fclean re
