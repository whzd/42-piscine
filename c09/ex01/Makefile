SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c

HDRS = includes/ft.h

OBJS = $(SRCS:.c=.o)

CFLAGS += -Wall -Wextra -Werror

NAME = libft.a

.c.o:
	cc $(CFLAGS) -c $< -o $(<:.c=.o) -I $(HDRS)

$(NAME): $(OBJS)
	ar cr $(NAME) $(OBJS)
	ranlib  $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
