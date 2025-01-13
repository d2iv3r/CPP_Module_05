/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:58:49 by efarhat           #+#    #+#             */
/*   Updated: 2023/12/09 14:05:48 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("presidential pardon", 25, 5), target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &t) : AForm("presidential pardon", 25, 5), target(t)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy) : AForm(cpy), target(cpy.target)
{
	*this = cpy;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &cpy)
{
	if (this != &cpy)
	{
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	try
	{
		AForm::execute(executor);
		std::cout << target << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
	}
	catch(const std::exception& e)
	{
		throw;
	}
}
