/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:05:36 by jpancorb          #+#    #+#             */
/*   Updated: 2025/05/29 17:26:28 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
: AForm("RobotomyRequest", 72, 45), _target(target)
{
	std::srand(std::time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
: AForm(other), _target(other._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	AForm::operator=(other);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

// action: drilling noises + 50% chance
void RobotomyRequestForm::executeAction(void) const
{
	std::cout << "Prrrr... trktrktrkppp... drilling noises..." << std::endl;
	if (std::rand() % 2)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy failed on " << _target << "." << std::endl;
}
