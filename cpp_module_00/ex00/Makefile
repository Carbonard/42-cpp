.PHONY: all clean fclean re

NAME = megaphone

SRC = megaphone.cpp

CPPFLAGS = -std=c++98 -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC)
	c++ $(CPPFLAGS) $^ -o $@

clean:

fclean:
	@rm -f $(NAME)

re: fclean all
