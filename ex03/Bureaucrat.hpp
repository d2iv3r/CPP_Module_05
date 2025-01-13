/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 10:17:05 by efarhat           #+#    #+#             */
/*   Updated: 2023/12/09 13:20:21 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include "AForm.hpp"
class AForm;

class Bureaucrat
{
    private:
        const std::string   name;
        int                 grade;
    public:
        class GradeTooHighException : public std::exception
        {
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            const char* what() const throw();
        };
        Bureaucrat();
        Bureaucrat(std::string const n, int g);
        Bureaucrat(const Bureaucrat &cpy);
        Bureaucrat &operator=(const Bureaucrat &cpy);
        ~Bureaucrat();

        std::string getName( void ) const;
        int getGrade( void ) const;

        void incGrade( void );
        void decGrade( void );

        void signForm(AForm &f);

        void executeForm(AForm const & form);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif
