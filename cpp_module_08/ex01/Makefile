.PHONY: all clean fclean re

NAME = test

SRC = main.cpp Span.cpp

DEP = Span.hpp

CPPFLAGS = -std=c++98 -Wall -Wextra -Werror

OBJ_DIR = obj

OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(CPPFLAGS) $^ -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp $(DEP) | $(OBJ_DIR)
	c++ $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
