NAME = a.out
CXX = clang++
CXXFLAGS = -Werror -Wextra -Wall
OBJS = new_stack.o

%.o : %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS)  $(OBJS) -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all