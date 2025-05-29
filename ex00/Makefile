# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/26 17:01:06 by jpancorb          #+#    #+#              #
#    Updated: 2025/05/29 19:47:18 by jpancorb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= i_want_to_be_a_bureaucrat
FLAGS	= -Wall -Wextra -Werror -std=c++98 
SRCS	= main.cpp Bureaucrat.cpp
OBJDIR	= obj/

OBJS	= $(SRCS:%.cpp=$(OBJDIR)%.o)

all: $(NAME)

$(NAME): $(OBJS)
		c++ -o $@ $^

$(OBJDIR)%.o: %.cpp Bureaucrat.hpp
		mkdir -p $(OBJDIR)
		c++ $(FLAGS) -c $< -o $@

clean:
		rm -rf $(OBJDIR)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re