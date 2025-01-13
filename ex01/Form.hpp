/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:48:53 by efarhat           #+#    #+#             */
/*   Updated: 2023/12/09 12:07:07 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"
class Bureaucrat;

class Form
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
		Form();
		Form(const std::string n, const int g, const int gE);
		Form(const Form &cpy);
		Form& operator=(const Form &cpy);
		~Form();

		std::string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(const Bureaucrat &b);
};

std::ostream &operator<<(std::ostream &out, const Form &f);

#endif
