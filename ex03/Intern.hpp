/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:07:31 by efarhat           #+#    #+#             */
/*   Updated: 2023/12/09 16:24:31 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		AForm* (Intern::*AformPtr)(const std::string &);
	public:
		Intern();
		Intern(const Intern &cpy);
		Intern& operator=(const Intern &cpy);
		~Intern();

		AForm* createShrubberyCreationForm(std::string const &t);
		AForm* createRobotomyRequestForm(std::string const &t);
		AForm* createPresidentialPardonForm(std::string const &t);
		AForm* makeForm(const std::string &form, const std::string &target);
};


#endif
