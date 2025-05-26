/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:49:02 by jpancorb          #+#    #+#             */
/*   Updated: 2025/05/26 19:01:56 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// File: Form.cpp

#include "Form.hpp"

// Constructor: validate grades, initialize members
Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false),
	  _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
}

// Copy constructor
Form::Form(const Form &other)
	: _name(other._name), _isSigned(other._isSigned),
	  _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

// Assignment operator: only _isSigned can change
Form &Form::operator=(const Form &other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

// Destructor
Form::~Form(void) {}

// Getters
const std::string &Form::getName(void) const
{
	return _name;
}

bool Form::isSigned(void) const
{
	return _isSigned;
}

int Form::getGradeToSign(void) const
{
	return _gradeToSign;
}

int Form::getGradeToExecute(void) const
{
	return _gradeToExecute;
}

// beSigned: if bureaucrat grade <= required, mark signed; else throw
void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

// Exception messages
const char *Form::GradeTooHighException::what(void) const throw()
{
	return "Form grade is too high!";
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return "Form or bureaucrat grade is too low!";
}

// operator<< overload
std::ostream &operator<<(std::ostream &out, const Form &f)
{
	out << "Form " << f.getName()
		<< " [sign grade " << f.getGradeToSign()
		<< ", exec grade " << f.getGradeToExecute()
		<< "], signed: " << (f.isSigned() ? "yes" : "no");
	return out;
}
