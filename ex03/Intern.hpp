/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:31:56 by jpancorb          #+#    #+#             */
/*   Updated: 2025/05/29 19:27:49 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

// declarations of concrete forms
class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;

class Intern
{
	private:
		// factory methods for each form type
		AForm *_makeShrubberyCreation(const std::string &target) const;
		AForm *_makeRobotomyRequest(const std::string &target) const;
		AForm *_makePresidentialPardon(const std::string &target) const;
		
	public:
		Intern(void);
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern(void);

		// create a form by name; returns nullptr if name unknown
		AForm *makeForm(const std::string &formName,
						const std::string &target) const;

};

#endif // INTERN_HPP
