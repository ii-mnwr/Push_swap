CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_PS = main.c ft_lstadd_front.c ft_lstadd_back.c ft_lstlast.c ft_lstnew.c ft_lstprint.c\
	ft_lstsize.c ft_memcpy.c ft_putstr.c ft_split.c ft_strlen.c ft_substr.c ft_atoi.c\
	ps_moves_1.c ps_moves_2.c ps_sorting.c ps_utils_1.c ps_utils_2.c\

SRC_CHECKER = get_next_line.c checker_utils.c ft_putendl_fd.c ft_strcmp.c checker.c ft_lstadd_front.c ft_lstadd_back.c ft_lstlast.c ft_lstnew.c ft_lstprint.c\
	ft_lstsize.c ft_memcpy.c ft_putstr.c ft_split.c ft_strlen.c ft_substr.c ft_atoi.c\
	ps_moves_1.c ps_moves_2.c ps_sorting.c ps_utils_1.c ps_utils_2.c ft_putstr_fd.c ft_putchar_fd.c\

OBJ_PS = $(SRC_PS:.c=.o)
OBJ_CHECKER = $(SRC_CHECKER:.c=.o)

NAME_PS = push_swap
NAME_CHECKER = checker

all: $(NAME_PS)

$(NAME_PS): $(OBJ_PS)
		@$(CC) $(CFLAGS) -o $@ $^

bonus: $(NAME_CHECKER)

$(NAME_CHECKER): $(OBJ_CHECKER)
		@$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
		$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJ_PS) $(OBJ_CHECKER)

fclean: clean
	@rm -f $(NAME_PS) $(NAME_CHECKER)

re: fclean all

.PHONY: all bonus clean fclean re