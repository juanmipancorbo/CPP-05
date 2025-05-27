/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:12:14 by jpancorb          #+#    #+#             */
/*   Updated: 2025/05/27 19:54:43 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat boss("Boss", 1);
	Bureaucrat intern("Intern", 150);

	ShrubberyCreationForm  shrub("home");
	RobotomyRequestForm    robo("Bender");
	PresidentialPardonForm pardon("Ford");

	// signing
	boss.signForm(shrub);
	boss.signForm(robo);
	boss.signForm(pardon);

	// attempting execution
	intern.executeForm(shrub);   // should fail by grade
	boss.executeForm(shrub);     // ok, creates file
	boss.executeForm(robo);      // ok, random
	boss.executeForm(pardon);    // ok, pardon message

	return 0;
}
