/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:47:08 by jpancorb          #+#    #+#             */
/*   Updated: 2025/05/27 19:52:42 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>

class AForm;

class Bureaucrat
{
	private:
		const std::string _name;
		int               _grade;

	public:
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat(void);

		// Accessors
		const std::string &getName(void) const;
		int	getGrade(void) const;

		// Modify grade by one step
		void incrementGrade(void);
		void decrementGrade(void);

		void signForm(AForm &f) const;
		void executeForm(const AForm &f) const;

		// Exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what(void) const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what(void) const throw();
		};
};

// Overload of the insertion operator for easy printing
std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif // BUREAUCRAT_HPP
