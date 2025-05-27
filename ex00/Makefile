# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/26 17:01:06 by jpancorb          #+#    #+#              #
#    Updated: 2025/05/27 18:06:22 by jpancorb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= form_up_maggots
SRCS	= main.cpp Bureaucrat.cpp
FLAGS	= -Wall -Wextra -Werror -std=c++98 
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