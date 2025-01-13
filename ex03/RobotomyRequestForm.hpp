/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:50:21 by efarhat           #+#    #+#             */
/*   Updated: 2023/12/09 15:35:42 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <cstdlib>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		const std::string target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &t);
		RobotomyRequestForm(const RobotomyRequestForm &cpy);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &cpy);
		~RobotomyRequestForm();

		void execute(Bureaucrat const & executor) const;
};

#endif
