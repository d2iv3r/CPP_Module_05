/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:51:57 by efarhat           #+#    #+#             */
/*   Updated: 2023/12/09 15:35:33 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		const std::string target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &t);
		PresidentialPardonForm(const PresidentialPardonForm &cpy);
		PresidentialPardonForm& operator=(const PresidentialPardonForm &cpy);
		~PresidentialPardonForm();

		void execute(Bureaucrat const & executor) const;
};

#endif
