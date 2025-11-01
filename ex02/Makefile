NAME =  program
SOURCES = Fixed.cpp main.cpp
FLAGS = g++ -Wall -Wextra -Werror -std=c++98
OBJ = $(SOURCES:.cpp=.o)
HEADER = Fixed.hpp
%.o: %.cpp
	$(FLAGS) -c $< -o $@

$(NAME): $(OBJ) $(HEADER)
	$(FLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all