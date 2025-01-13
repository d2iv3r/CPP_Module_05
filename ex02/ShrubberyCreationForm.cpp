/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:56:34 by efarhat           #+#    #+#             */
/*   Updated: 2023/12/09 15:07:14 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery creation", 145, 137), target("default")
{
	tree =
		"      (^^^^^^^)\n"
		"    (           )\n"
		"  (       -0-     )\n"
		"(   -0-             )\n"
		" (           -1-   )\n"
		"   <    -1-      >\n"
		"      \\       /\n"
		"        -   -\n"
		"        |   |\n"
		"        |   |\n"
		"        |   |\n"
		"  ......|___|....../\n"
		"  ................./\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string t) : AForm("shrubbery creation", 145, 137), target(t + "_shrubbery")
{
	tree =
		"      (^^^^^^^)\n"
		"    (           )\n"
		"  (       -0-     )\n"
		"(   -0-             )\n"
		" (           -1-   )\n"
		"   <    -1-      >\n"
		"      \\       /\n"
		"        -   -\n"
		"        |   |\n"
		"        |   |\n"
		"        |   |\n"
		"  ......|___|....../\n"
		"  ................./\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy) : AForm(cpy)
{
	*this = cpy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &cpy)
{
	if (this != &cpy)
	{
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	try
	{
		AForm::execute(executor);
		std::ofstream out;
		out.open(this->target.c_str());
		if (!out.is_open())
			throw std::ios_base::failure("Error opening the file");
		out << tree;
		if (out.fail())
			throw std::ios_base::failure("Error writing ascii tree inside file");
		out.close();
		std::cout << "Shrubbery Creation executed Successfully!" << std::endl;
	}
	catch(const std::exception& e)
	{
		throw;
	}
}
