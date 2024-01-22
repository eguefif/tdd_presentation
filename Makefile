NAME=TDD

SRC = main.c

all: $(NAME)

$(NAME): $(SRC)
	cc -Wall -Wextra -Werror -Iincludes -lft -L./libft $(SRC) -o $(NAME)

clean:

fclean:
	rm -rfo $(TDD)

re: fclean all

.phony: all clean fclean re
