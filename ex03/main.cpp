#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"


int main()
{
	Intern someRandomIntern;
	AForm* rrf;

	rrf = someRandomIntern.makeForm("shrubbery creation", "Shrubb");
	if (rrf)
	{
		std::cout << *rrf << std::endl;
		delete rrf;
	}
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf)
	{
		std::cout << *rrf << std::endl;
		delete rrf;
	}
	rrf = someRandomIntern.makeForm("presidential pardon", "pardon");
	if (rrf)
	{
		std::cout << *rrf << std::endl;
		delete rrf;
	}
	rrf = someRandomIntern.makeForm("uknown form", "error");
	if (rrf)
	{
		std::cout << *rrf << std::endl;
		delete rrf;
	}
	return 0;
}
