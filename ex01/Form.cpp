/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:54:30 by efarhat           #+#    #+#             */
/*   Updated: 2023/12/09 12:12:53 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("default"), gradeToSign(100), gradeToExec(100)
{
	_signed = false;
}

Form::Form(const std::string n, const int gS, const int gE) : name(n), gradeToSign(gS), gradeToExec(gE)
{
	_signed = false;
	if (gradeToSign < 1 || gradeToExec < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &cpy) : name(cpy.name), gradeToSign(cpy.getGradeToSign()), gradeToExec(cpy.getGradeToExecute())
{
	_signed = cpy.getSigned();
}

Form& Form::operator=(const Form &cpy)
{
	if (this != &cpy)
	{
		_signed = cpy.getSigned();
	}
	return (*this);
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "The Grade is too high (exception)!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "The Grade is too low (exception)!";
}

std::string Form::getName() const { return (this->name); };
int Form::getGradeToSign() const { return (this->gradeToSign); };
int Form::getGradeToExecute() const { return (this->gradeToExec); };
bool Form::getSigned() const { return (this->_signed); };

std::ostream &operator<<(std::ostream &out, const Form &f)
{
	std::cout << "Form " << f.getName() << ", is signed " << f.getSigned() << ", grade to signe " << f.getGradeToSign() << ", grade to execute " << f.getGradeToExecute();
	return (out);
}

Form::~Form()
{
};

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->gradeToSign)
		throw Form::GradeTooLowException();
	else
		this->_signed = true;
}
