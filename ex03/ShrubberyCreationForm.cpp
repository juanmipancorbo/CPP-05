/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:02:56 by jpancorb          #+#    #+#             */
/*   Updated: 2025/05/27 19:22:50 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

// constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
: AForm("ShrubberyCreation", 145, 137), _target(target) {}

// copy
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
: AForm(other), _target(other._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	AForm::operator=(other);
	// _target is const, not assigned
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

// action: create file and draw ASCII trees
void ShrubberyCreationForm::executeAction(void) const
{
	std::string filename = _target + "_shrubbery";
    std::ofstream ofs(filename.c_str());
	if (!ofs)
		return;
	ofs << "   ccee88oo\n"
		   "  C8O8O8Q8PoOb o8oo\n"
		   " dOB69QO8PdUOpugoO9bD\n"
		   "CgggbU8OU qOp qOdoUOdcb\n"
		   "    6OuU  /p u gcoUodpP\n"
		   "      \\\\//  /douUP\n"
		   "        \\\\////\n"
		   "         |||/\\\n"
		   "         |||\\/\n"
		   "         |||||\n"
		   "   .....//||||\\....\n";
}
