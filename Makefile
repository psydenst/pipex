SRCS_FILES	=	${shell find ./src -name "*.c"}
SRCS_BONUS	=	${shell find ./src_bonus	-name "*.c"}

SRC		=	${SRCS_FILES}
SRC_BONUS	=	${SRCS_BONUS}

OBJ		=	${SRC:.c=.o}
OBJ_BONUS	=	${SRC_BONUS:.c=.o}

NAME		=	pipex
LIBFT		=	./inc/ft_printf/libft
CC		=	gcc
CFLAGS		=	-Wall -Wextra -Werror 
INCLUDE		=	-I./inc/pipex.h


all:	$(NAME)
	
$(NAME):	$(OBJ) inc/pipex.h
		make -C ${LIBFT}
		${CC} ${CFLAGS} ${INCLUDE} ${LIBFT}/libft.a ${OBJ} -o $(NAME)


clean:
	make clean -C ${LIBFT}
	rm -rf $(OBJ)

fclean:	clean
	make fclean -C ${LIBFT}
	rm -rf $(NAME)

re:	fclean all

.PHONY: make all clean fclean
