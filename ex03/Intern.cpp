/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:13:17 by efarhat           #+#    #+#             */
/*   Updated: 2023/12/09 16:34:02 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &cpy)
{
	*this = cpy;
}

Intern& Intern::operator=(const Intern &cpy)
{
	if (this != &cpy)
	{
	}
	return *this;
}

AForm* Intern::createShrubberyCreationForm(std::string const &t) { return (new ShrubberyCreationForm(t));};
AForm* Intern::createRobotomyRequestForm(std::string const &t) { return (new RobotomyRequestForm(t));};
AForm* Intern::createPresidentialPardonForm(std::string const &t) { return (new PresidentialPardonForm(t));};

AForm* Intern::makeForm(const std::string &form, const std::string &target)
{
	AForm* (Intern::*p[3])(const std::string &) = {
				&Intern::createShrubberyCreationForm,
				&Intern::createRobotomyRequestForm,
				&Intern::createPresidentialPardonForm};
	const std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (int i = 0; i < 3; i++)
	{
		if (form == forms[i])
		{
			this->AformPtr = p[i];
			std::cout << "Intern creates " << forms[i] << std::endl;
			return((this->*AformPtr)(target));
		}
	}
	std::cout << "Intern can't create '" << form << "' the form not exist!" << std::endl;
	return (NULL);
}

Intern::~Intern()
{
}

