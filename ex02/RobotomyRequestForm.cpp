/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:58:09 by efarhat           #+#    #+#             */
/*   Updated: 2023/12/09 15:08:49 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy request", 72, 45), target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &t) : AForm("robotomy request", 72, 45), target(t)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy) : AForm(cpy), target(cpy.target)
{
	*this = cpy;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &cpy)
{
	if (this != &cpy)
	{
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	try
	{
		AForm::execute(executor);
		srand(time(0));
		if ((rand() % 2) == 0)
		{
			std::cout << "drilling noises ... ... ..." << std::endl;
			std::cout << target << " has been robotomized successfully!" << std::endl;
		}
		else
			std::cout << "The robotomized failed!!" << std::endl;
	}
	catch(const std::exception& e)
	{
		throw;
	}
}
