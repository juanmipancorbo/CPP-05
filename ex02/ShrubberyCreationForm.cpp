/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:02:56 by jpancorb          #+#    #+#             */
/*   Updated: 2025/05/28 19:51:15 by jpancorb         ###   ########.fr       */
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
	ofs <<	"           &&& &&  & &&           &&& &&  & &&  \n"
			"       && &\\/&\\|& ()|/ @, &&   && &\\/&\\|& ()|/ @, &&\n"
			"       &\\/(/&/&||/& /_/)_&/_&   &\\/(/&/&||/& /_/)_&/_&\n"
			"    &() &\\/&|()|/&\\/ '%\" & () &() &\\/&|()|/&\\/ '%\" & ()\n"
			"   &_\\_&&_\\ |& |&&/&__%_/_& &&&_\\\\_&&_\\ |& |&&/&__%_/_& &&\n"
			" &&   && & &| &| /& & % ()& /&&  &&   && & &| &| /& & % ()& /&&\n"
			"    ()&_---()&\\&\\|&&-&&--%---()~   ()&_---()&\\&\\|&&-&&--%---()~\n"
			"       &&     \\|||                  &&     \\|||\n"
			"               |||                          |||\n"
			"               |||                          |||\n"
			"               |||                          |||\n"
			"         , -=-~  .-^- _            , -=-~  .-^- _\n";
}
