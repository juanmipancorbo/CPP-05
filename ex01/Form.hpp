/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:46:42 by jpancorb          #+#    #+#             */
/*   Updated: 2025/05/26 19:03:35 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Form
	{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		Form(const std::string &name, int gradeToSign, int gradeToExecute);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form(void);

		// Getters
		const std::string &getName(void) const;
		bool	isSigned(void) const;
		int		getGradeToSign(void) const;
		int		getGradeToExecute(void) const;

		// Attempt to be signed by a bureaucrat
		void beSigned(const Bureaucrat &b);

		// Exception if grade too high
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what(void) const throw();
		};

		// Exception if grade too low
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what(void) const throw();
		};
	};

// Overload of insertion operator to print form info
std::ostream &operator<<(std::ostream &out, const Form &f);

#endif // FORM_HPP
