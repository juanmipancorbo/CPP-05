/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:16:24 by jpancorb          #+#    #+#             */
/*   Updated: 2025/05/26 19:29:18 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat a("Violeta", 50);
	Form       f1("Form-A", 30, 20);
	Form       f2("Form-B", 70, 40);

	std::cout << a << std::endl;
	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;

	// Violeta tries to sign both forms
	a.signForm(f1);  // will fail
	a.signForm(f2);  // will succeed

	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;

	// test invalid form creation
	try
	{
		Form invalid("BadForm", 0, 10);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception creating form: "
				<< e.what()
				<< std::endl;
	}

	return 0;
}
