# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/03 22:19:28 by macbookpro        #+#    #+#              #
#    Updated: 2025/04/05 09:55:30 by macbookpro       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = abstract_animals

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

OBJ_DIR = obj

SRCS = main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: %.cpp Animal.hpp Dog.hpp Cat.hpp Brain.hpp
	@mkdir -p $(OBJ_DIR) # Create the object directory if it doesn't exist
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR) # Remove the entire object directory

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re