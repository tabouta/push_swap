NAME = push_swap

NAME_LIB = libft.a

PATH_LIB = libft/

AR = ar rcs

CC = cc

FLAGS =  -Werror -Wextra -Wall

SRCS = push_swap.c mouvement.c parsing.c parsing2.c split.c utils.c mouvement2.c mouvement3.c \
	number_to_mv.c  push_number.c minmax.c minisort.c libft.c

OBJS =$(SRCS:.c=.o)

all: $(NAME) 

$(NAME):
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)
$(NAME_LIB):
	@make -C $(PATH_LIB)
clean:
	rm -f $(NAME_LIB) $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all .c.o