NAME	=	libft.a 

SRCS	=	ft_atoi.c		ft_isalpha.c		ft_strdup.c\
			ft_memcpy.c		ft_bzero.c			ft_substr.c\
			ft_tolower.c	ft_memmove.c		ft_isalnum.c\
			ft_isascii.c	ft_strncmp.c		ft_memset.c\
			ft_strlcat.c	ft_isdigit.c		ft_strjoin.c\
			ft_toupper.c	ft_calloc.c			ft_strtrim.c\
			ft_memchr.c		ft_strrchr.c		ft_split.c\
			ft_strlcpy.c	ft_strnstr.c		ft_substr.c\
			ft_isprint.c	ft_memcmp.c			ft_itoa.c\
			ft_strchr.c		ft_strlen.c			ft_strmapi.c\
			ft_striteri.c	ft_putchar_fd.c		ft_putstr_fd.c\
			ft_putendl_fd.c	ft_putnbr_fd.c
			

OBJS	=	$(SRCS:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
NAME		= libft.a
all:		$(NAME)
$(NAME):	$(OBJS) $(INC)
			ar rcs $(NAME) $(OBJS)
clean:
			$(RM) $(OBJS) $(BONUS_OBJS)
fclean:	clean
			$(RM) $(NAME)
re:			fclean $(NAME)
.PHONY:	all clean fclean re bonus