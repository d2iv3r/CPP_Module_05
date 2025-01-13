/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 10:17:05 by efarhat           #+#    #+#             */
/*   Updated: 2023/12/09 12:00:18 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

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
        Bureaucrat(const std::string n, int g);
        Bureaucrat(const Bureaucrat &cpy);
        Bureaucrat &operator=(const Bureaucrat &cpy);
        ~Bureaucrat();

        std::string getName( void ) const;
        int getGrade( void ) const;

        void incGrade( void );
        void decGrade( void );
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif
