#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	//////////// shrubbery //////////
	try
	{
		ShrubberyCreationForm shrub("test");
		Bureaucrat b("Ahmed", 130);
		shrub.beSigned(b);
		shrub.execute(b);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	/////////// RobotomyRequest //////
	try
	{
		RobotomyRequestForm robo("robocop");
		Bureaucrat b("Ahmed", 40);
		robo.beSigned(b);
		robo.execute(b);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	///////// Presidentil pardon ////////
	try
	{
		PresidentialPardonForm pard("Evaluator");
		Bureaucrat b("Ahmed", 5);
		pard.beSigned(b);
		pard.execute(b);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	///////// Bureacrat execute Forms //////////
	try
	{
		Bureaucrat b("Ahmed", 50);
		ShrubberyCreationForm sh("ahmed");
		RobotomyRequestForm robo("test");
		PresidentialPardonForm pard("Ahmed");
		b.signForm(sh);
		b.signForm(robo);
		b.signForm(pard);
		b.executeForm(sh);
		b.executeForm(robo);
		b.executeForm(pard);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
