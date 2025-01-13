/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 10:23:25 by efarhat           #+#    #+#             */
/*   Updated: 2023/12/09 12:19:49 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(100)
{
};

Bureaucrat::Bureaucrat(const std::string n, int g) : name(n)
{
    if (g < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (g > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        grade = g;
};

Bureaucrat::Bureaucrat(const Bureaucrat &cpy) : name(cpy.getName())
{
    grade = cpy.getGrade();
};

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &cpy)
{
    if (this != &cpy)
        grade = cpy.getGrade();
    return (*this);
}

std::string Bureaucrat::getName( void ) const
{
    return (name);
};

int Bureaucrat::getGrade( void ) const
{
    return (grade);
};

void Bureaucrat::incGrade( void )
{

    if (--this->grade <= 0)
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decGrade( void )
{
    if (++this->grade)
        throw Bureaucrat::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
    std::cout << b.getName() << ", bureaucrat grade " << b.getGrade();
    return (out);
};

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "The Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "The Grade is too low!";
}

Bureaucrat::~Bureaucrat()
{
}

void Bureaucrat::signForm(Form &f)
{
    try
    {
        f.beSigned(*this);
        std::cout << this->getName() << " signed " << f.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << this->getName() << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
    }
}
