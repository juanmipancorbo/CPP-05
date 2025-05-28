/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:48:42 by jpancorb          #+#    #+#             */
/*   Updated: 2025/05/28 19:40:09 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

// Constructor: check range, initialize members
Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

// Copy constructor: copy name and grade
Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name)
{
	_grade = other._grade;
}

// Assignment: only grade can change, name is const
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		_grade = other._grade;
	return *this;
}

// Destructor
Bureaucrat::~Bureaucrat(void) {}

// Getter for name
const std::string &Bureaucrat::getName(void) const
{
	return _name;
}

// Getter for grade
int Bureaucrat::getGrade(void) const
{
	return _grade;
}

// Decrease numerical grade by one
void Bureaucrat::incrementGrade(void)
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

// Increase numerical grade by one
void Bureaucrat::decrementGrade(void)
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(Form &f) const
{
	try
	{
		f.beSigned(*this);
		std::cout << _name
				<< " signed "
				<< f.getName()
				<< std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _name
				<< " couldn’t sign "
				<< f.getName()
				<< " because "
				<< e.what()
				<< std::endl;
	}
}

// Exception messages
const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "Grade is too low!";
}

// Stream insertion overload
std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << b.getName()
		<< ", bureaucrat grade "
		<< b.getGrade()
		<< ".";
	return out;
}
