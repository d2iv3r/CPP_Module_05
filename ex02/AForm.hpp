/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:54:26 by efarhat           #+#    #+#             */
/*   Updated: 2023/12/09 15:10:25 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool				_signed;
		const int			gradeToSign;
		const int			gradeToExec;
	public:
		class GradeTooHighException : public std::exception
		{
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			const char* what() const throw();
		};
		class FormNotSignedException : public std::exception
		{
			const char* what() const throw();
		};
		AForm();
		AForm(const std::string n, const int g, const int gE);
		AForm(const AForm &cpy);
		AForm& operator=(const AForm &cpy);
		virtual ~AForm();

		std::string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(const Bureaucrat &b);

		virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream &out, AForm &f);

#endif
