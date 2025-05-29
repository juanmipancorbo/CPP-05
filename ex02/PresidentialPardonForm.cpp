/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:07:33 by jpancorb          #+#    #+#             */
/*   Updated: 2025/05/29 17:27:24 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
: AForm("PresidentialPardon", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
: AForm(other), _target(other._target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	AForm::operator=(other);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

// action: pardon message
void PresidentialPardonForm::executeAction(void) const
{
	std::cout << _target
	          << " has been pardoned by Zaphod Beeblebrox."
	          << std::endl;
}
