NAME		= harlthekaren

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRC			= main.cpp Harl.cpp
OBJ			= $(SRC:.cpp=.o)

all:$(NAME)
$(NAME):$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean:clean
	rm -rf $(NAME)
re:fclean all
.PHONY: re all fclean clean