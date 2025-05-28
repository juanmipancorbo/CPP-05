/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:12:14 by jpancorb          #+#    #+#             */
/*   Updated: 2025/05/28 17:47:50 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
	Intern		someRandomIntern;
	AForm		*form1;
	AForm		*form2;
	AForm		*form3;
	AForm		*form4;
	Bureaucrat	final_boss("Final_Boss", 1);
	Bureaucrat	new_intern("New_Intern", 150);

	// Intern tries to create each form
	form1 = someRandomIntern.makeForm("shrubbery creation", "Bart");
	form2 = someRandomIntern.makeForm("robotomy request", "Roby");
	form3 = someRandomIntern.makeForm("presidential pardon", "Felipe");
	form4 = someRandomIntern.makeForm("unknown form", "Nobody");

	std::cout << std::endl;

	// Signing and executing with high-ranked bureaucrat
	if (form1)
	{
		final_boss.signForm(*form1);
		final_boss.executeForm(*form1);
	}
	if (form2)
	{
		final_boss.signForm(*form2);
		final_boss.executeForm(*form2);
	}
	if (form3)
	{
		final_boss.signForm(*form3);
		final_boss.executeForm(*form3);
	}

	std::cout << std::endl;

	// Attempt execution with low-ranked bureaucrat (should fail)
	if (form1)
		new_intern.executeForm(*form1);

	// Clean up
	delete form1;
	delete form2;
	delete form3;
	delete form4;

	return 0;
}
