
SRCS	=	ps_atoi.c\
		ps_list_methods_1.c\
		ps_list_methods_2.c\
		ps_list_methods_3.c\
		ps_operations_1.c\
		ps_operations_2.c\
		ps_operations_3.c\
		ps_other_utils.c\
		ps_parser_1.c\
		ps_parser_2.c\
		ps_sorting_1.c\
		ps_sorting_2.c\
		ps_sorting_3.c\

SRCS_MAIN =	ps_main.c\


SRCS_BONUS =	ps_checker_utils_1_bonus.c\
		ps_checker_utils_2_bonus.c\
		get_next_line/get_next_line.c\
		get_next_line/get_next_line_utils.c\
		
OBJS		= ${SRCS:.c=.o}

OBJS_BONUSES 	= ${SRCS_BONUS:.c=.o}

OBJ_MAIN 	= ${SRCS_MAIN:.c=.o}

NAME		= push_swap

NAME_BONUS 	= checker

HEADER		= push_swap.h

HEADER_2		= get_next_line/get_next_line.h

CC		= cc

CFLAGS		= -Wall -Wextra -Werror

INCLUDES 	= libft/libft.a

.c.o:	
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS) $(OBJ_MAIN) $(HEADER)
	make -C libft/
	$(CC) $(OBJS) $(OBJ_MAIN) -o $(NAME) $(FLAGS) $(INCLUDES)
	make clean

$(NAME_BONUS): $(OBJS) $(OBJS_BONUSES) $(HEADER) $(HEADER_2)
	make -C libft/
	$(CC) $(OBJS) $(OBJS_BONUSES) -o $(NAME_BONUS) $(FLAGS) $(INCLUDES)
	make clean

clean:
	@rm -rf ${OBJS} $(OBJ_MAIN) ${OBJS_BONUSES}
	@make -C libft/ clean

fclean:	clean
	@rm -rf ${NAME}
	@rm -rf ${NAME_BONUS}
	@make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re bonus
