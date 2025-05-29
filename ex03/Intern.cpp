/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:32:54 by jpancorb          #+#    #+#             */
/*   Updated: 2025/05/29 19:36:56 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// constructor
Intern::Intern(void) {}

// copy constructor
Intern::Intern(const Intern &other)
{
	(void)other;
}

// assignment operator
Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

// destructor
Intern::~Intern(void) {}

// factory helper: shrubbery
AForm *Intern::_makeShrubberyCreation(const std::string &target) const
{
	return new ShrubberyCreationForm(target);
}

// factory helper: robotomy
AForm *Intern::_makeRobotomyRequest(const std::string &target) const
{
	return new RobotomyRequestForm(target);
}

// factory helper: presidential pardon
AForm *Intern::_makePresidentialPardon(const std::string &target) const
{
	return new PresidentialPardonForm(target);
}

// makeForm: choose correct factory or report error
AForm *Intern::makeForm(const std::string &formName,
                        const std::string &target) const
{
	// table of forms
	const std::string names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	// member function pointers
	AForm *(Intern::*makers[3])(const std::string &) const =
	{
		&Intern::_makeShrubberyCreation,
		&Intern::_makeRobotomyRequest,
		&Intern::_makePresidentialPardon
	};

	for (int i = 0; i < 3; ++i)
	{
		if (formName == names[i])
		{
			AForm *f = (this->*makers[i])(target);
			std::cout << "Intern creates " << f->getName() << std::endl;
			return f;
		}
	}

	std::cout << "Intern cannot create \""
	          << formName
	          << "\" because this form name does not exist" << std::endl;
	return NULL;
}
