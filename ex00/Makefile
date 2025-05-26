# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/26 17:01:06 by jpancorb          #+#    #+#              #
#    Updated: 2025/05/26 18:38:05 by jpancorb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= form_up_maggots
SRCS		= main.cpp Bureaucrat.cpp
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 
OBJDIR		= obj/

OBJS	= $(SRCS:%.cpp=$(OBJDIR)%.o)

all: $(NAME)

$(NAME): $(OBJS)
		c++ $(CXXFLAGS) -o $@ $^

$(OBJDIR)%.o: %.cpp
		mkdir -p $(OBJDIR)
		c++ $(CXXFLAGS) -c $< -o $@

clean:
		rm -rf $(OBJDIR)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re