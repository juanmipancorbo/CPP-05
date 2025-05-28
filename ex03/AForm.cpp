/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:59:39 by jpancorb          #+#    #+#             */
/*   Updated: 2025/05/27 19:42:32 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// constructor: initialize and validate grades
AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
}

// copy constructor
AForm::AForm(const AForm &other) : _name(other._name), _isSigned(other._isSigned),
	_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

// assignment: only signed status can change
AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

// destructor
AForm::~AForm(void) {}

// getters
const std::string &AForm::getName(void) const
{
	return _name;
}

bool AForm::isSigned(void) const
{
	return _isSigned;
}

int AForm::getGradeToSign(void) const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute(void) const
{
	return _gradeToExecute;
}

// signing
void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

// execution entry point
void AForm::execute(const Bureaucrat &executor) const
{
	if (!_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
	executeAction();
}

// exception messages
const char *AForm::GradeTooHighException::what(void) const throw()
{
	return "Form grade is too high!";
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return "Form grade is too low!";
}

const char *AForm::FormNotSignedException::what(void) const throw()
{
	return "Form is not signed!";
}

// operator<<
std::ostream &operator<<(std::ostream &out, const AForm &f)
{
	out << "Form " << f.getName()
		<< " [sign " << f.getGradeToSign()
		<< ", exec " << f.getGradeToExecute()
		<< "], signed: " << (f.isSigned() ? "yes" : "no");
	return out;
}
