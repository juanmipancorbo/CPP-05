/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:47:08 by jpancorb          #+#    #+#             */
/*   Updated: 2025/05/26 19:08:26 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>

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

		// Exception thrown when grade < 1
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what(void) const throw();
		};

		// Exception thrown when grade > 150
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what(void) const throw();
		};
};

// Overload of the insertion operator for easy printing
std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif // BUREAUCRAT_HPP
