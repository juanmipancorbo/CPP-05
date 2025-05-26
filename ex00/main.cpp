/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:16:24 by jpancorb          #+#    #+#             */
/*   Updated: 2025/05/26 18:38:01 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat a("Alice", 1);
		std::cout << a << std::endl;
		// This will throw, since grade would become 0
		a.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: "
		          << e.what()
		          << std::endl;
	}

	try
	{
		Bureaucrat b("Bob", 150);
		std::cout << b << std::endl;
		// This will throw, since grade would become 151
		b.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: "
		          << e.what()
		          << std::endl;
	}

	try
	{
		// Invalid initial grade
		Bureaucrat c("Charlie", 0);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught while creating Charlie: "
		          << e.what()
		          << std::endl;
	}

	return 0;
}
