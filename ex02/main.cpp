/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:12:14 by jpancorb          #+#    #+#             */
/*   Updated: 2025/05/28 17:23:42 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat final_boss("Final_Boss", 1);
	Bureaucrat new_intern("New_Intern", 150);

	ShrubberyCreationForm  shrub("Bart");
	RobotomyRequestForm    robo("Roby");
	PresidentialPardonForm pardon("Felipe");

	// signing
	final_boss.signForm(shrub);
	final_boss.signForm(robo);
	final_boss.signForm(pardon);

	// attempting execution
	new_intern.executeForm(shrub);   // should fail by grade
	final_boss.executeForm(shrub);     // ok, creates file
	final_boss.executeForm(robo);      // ok, random
	final_boss.executeForm(pardon);    // ok, pardon message

	return 0;
}
