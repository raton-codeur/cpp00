NAME = ex02
FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp Account.cpp
OBJS = $(SRCS:.cpp=.o)

%.o : %.cpp
	c++ $(FLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	c++ $(FLAGS) $(OBJS) -o $@

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

test : all
	./$(NAME)
	
.PHONY: all clean fclean re