NAME		=	pipex
LIBFT_PATH	= ./inc/ft_printf/libft
LIBFT		= $(LIBFT_PATH)/libft.a

SRCS_FILES	=	 ${shell find ./src -name "*.c"}
#
#	MISSING BONUS
#

SRCS_MAN	= $(SRCS_FILES)
OBJS_MAN	= ${SRCS_FILES:.c=.o}
#
#	MISSING BONUS
#

INCLUDE		= -I./inc/pipex.h
#
#	MISSING BONUS
#

CC	=	cc
CFLAGSq	= -Wall -Wextra -Werror
RM	= rm -rf

all:	$(NAME)

$(NAME):	$(OBJS_MAN) inc/pipex.h
			make -C $(LIBFT_PATH)
			@$(CC) $(CFLAGS) $(HEADER) $(LIBFT_PATH)/libft.a $(OBJS_MAN) -o $(NAME)

#
# bonus: MISSING BONUS
#

%.o:	%.c	libft/*.c
		@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:	
		make clean -C $(LIBFT_PATH)
		$(RM) $(OBJS_MAN)
		#
		# $(RM) $(OBJS_MAN)
		#

fclean:	clean
		make fclean -C $(LIBFT_PATH)
		$(RM) $(NAME)
	
re:		fclean all

.PHONY:	all clean fclean re # bonus
