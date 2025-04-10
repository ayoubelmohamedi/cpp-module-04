# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/05 10:40:11 by macbookpro        #+#    #+#              #
#    Updated: 2025/04/05 10:42:38 by macbookpro       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = materia
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

SRCS = main.cpp AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp
OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
HEADERS = AMateria.hpp Ice.hpp Cure.hpp Character.hpp MateriaSource.hpp

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re $(OBJ_DIR)
