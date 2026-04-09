CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = ScalarConverter.cpp main.cpp
OBJ  = $(SRCS:.cpp=.o)
NAME = convert

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re