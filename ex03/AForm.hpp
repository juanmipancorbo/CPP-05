/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:57:17 by jpancorb          #+#    #+#             */
/*   Updated: 2025/05/27 19:33:23 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	protected:
		virtual void executeAction(void) const = 0; // pure virtual

	public:
		AForm(const std::string &name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm(void);

		// getters
		const std::string &getName(void) const;
		bool               isSigned(void) const;
		int                getGradeToSign(void) const;
		int                getGradeToExecute(void) const;

		void beSigned(const Bureaucrat &b);
		void execute(const Bureaucrat &executor) const;

		// exceptions
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

		class FormNotSignedException : public std::exception
		{
			public:
				const char *what(void) const throw();
		};
};

// insertion operator
std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif // AFORM_HPP
