.PHONY: all clean fclean re

NAME = hiThisIsBrain

SRC = main.cpp

CPPFLAGS = -std=c++98 -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC)
	c++ $(CPPFLAGS) $^ -o $@

clean:

fclean:
	rm -f $(NAME)

re: fclean all
