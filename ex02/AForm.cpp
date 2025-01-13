/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:12:08 by efarhat           #+#    #+#             */
/*   Updated: 2023/12/09 14:47:59 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("default"), gradeToSign(100), gradeToExec(100)
{
	_signed = false;
}

AForm::AForm(const std::string n, const  int gS, const int gE) : name(n), gradeToSign(gS), gradeToExec(gE)
{
	_signed = false;
	if (gradeToSign < 1 || gradeToExec < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &cpy) : name(cpy.name), gradeToSign(cpy.getGradeToSign()), gradeToExec(cpy.getGradeToExecute())
{
	_signed = cpy.getSigned();
}

AForm& AForm::operator=(const AForm &cpy)
{
	if (this != &cpy)
	{
		_signed = cpy.getSigned();
	}
	return (*this);
}

const char* AForm::GradeTooHighException::what() const throw() { return ("Grade too hight (exception)!");};

const char* AForm::GradeTooLowException::what() const throw() { return ("Grade too low (exception)!");};

const char*AForm::FormNotSignedException::what() const throw() { return ("Form not signed (exception)!");};

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->gradeToSign)
		throw AForm::GradeTooLowException();
	else
		this->_signed = true;
}

std::string AForm::getName() const { return (this->name); };
int AForm::getGradeToSign() const { return (this->gradeToSign); };
int AForm::getGradeToExecute() const { return (this->gradeToExec); };
bool AForm::getSigned() const { return (this->_signed); };

std::ostream &operator<<(std::ostream &out, AForm &f)
{
	std::cout << "Form " << f.getName() << ", is signed " << f.getSigned() << ", grade to signe " << f.getGradeToSign() << ", grade to execute " << f.getGradeToExecute();
	return (out);
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned())
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
}

AForm::~AForm()
{
};
