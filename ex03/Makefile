# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/26 17:01:06 by jpancorb          #+#    #+#              #
#    Updated: 2025/05/28 17:42:18 by jpancorb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= no_you_need_form_28b_not_28c
FLAGS	= -Wall -Wextra -Werror -std=c++98 -MMD -MP
SRCS	= main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
OBJDIR	= obj/

OBJS	= $(SRCS:%.cpp=$(OBJDIR)%.o)
DEPS	= $(SRCS:%.cpp=$(OBJDIR)%.d)

all: $(NAME)

$(NAME): $(OBJS)
		c++ -o $@ $^

$(OBJDIR):
		mkdir -p $@

$(OBJDIR)%.o: %.cpp | $(OBJDIR)
		c++ $(FLAGS) -c $< -o $@

-include $(DEPS)

clean:
		rm -rf $(OBJDIR)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re