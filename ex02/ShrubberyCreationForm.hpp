/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:45:51 by efarhat           #+#    #+#             */
/*   Updated: 2023/12/09 13:09:31 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "AForm.hpp"
class AForm;

class ShrubberyCreationForm : public AForm
{
	private:
		const std::string target;
		std::string tree;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &cpy);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &cpy);
		~ShrubberyCreationForm();

		void execute(Bureaucrat const & executor) const;
};

#endif
