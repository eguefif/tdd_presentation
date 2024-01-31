NAME=TDD

SRC = main.c
CC = cc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(SRC)
	cc -Wall -Wextra -Werror -Iincludes -lft -L./ $(SRC) -o $(NAME)

test_parser2: ./src/parser.o
	$(CC) $(CFLAGS) -c ./test/test_parser.c -o ./test/test_parser.o -I./includes
	$(CC) $(CFLAGS) -L./ -Lft -I./includes -o test_parser $^ ./test/test_parser.o
	mv test_parser ./test
	rm ./test/*.o

test_parser: ./src/parser.c ./test/test_parser.c
	$(CC) $(CFLAGS) -L./ -Lft -I./includes -o test_parser $^
	mv test_parser ./test

./src/%.o: ./src/%.c 
	$(CC) $(CFLAGS) -c $< -o $@ -I./includes

test: test_parser
	@cd ./test
	./run_test.sh

clean:

fclean:
	rm -rfo $(TDD)

re: fclean all

.PHONY: all clean fclean re test
