NAME = push_swap

SRCS =	main.c\
		\
		instructions/push.c\
		instructions/swap.c\
		instructions/rotate.c\
		\
		algorithms/ft_simple_sort.c\
		algorithms/ft_quick_sort.c\
		algorithms/ft_merge_sort.c\
		algorithms/ft_insert_sort.c\
		algorithms/ft_push_swap_sort.c\
		\
		utilities/sort_utils.c\
		utilities/valid_utils.c\
		utilities/parse_utils.c\
		utilities/rotate_utils.c\
		utilities/quick_sort_utils.c\
		utilities/merge_sort_utils.c\
		utilities/insert_sort_utils.c\
		utilities/stack_utils.c\
		utilities/free_utils.c\
		utilities/errors_utils.c\

LIB = libft.a
LIB_SRC = ./libft

OBJS = $(SRCS:%.c=%.o)
HEADER = push_swap.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror

.PHONY	: all clean fclean re bonus

all		: $(LIB) $(NAME)

$(NAME)	: $(OBJS) $(LIB_SRC)/$(LIB)
	$(CC) $(OBJS) $(LIB_SRC)/$(LIB) -o $(NAME)

$(LIB)	:
	make all -C $(LIB_SRC)

%.o		: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	$(MAKE) clean -C $(LIB_SRC)
	rm -f $(OBJS)

fclean	: clean
	$(MAKE) fclean -C $(LIB_SRC)
	rm -f $(NAME)

re		: fclean all