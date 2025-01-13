# include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b("ahmed", 150);
        std::cout << b << std::endl;
    }
    catch(const std::exception & e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Bureaucrat b("ahmed", 1);
        b.incGrade();
    }
    catch(const std::exception & e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Bureaucrat b("ahmed", 150);
        b.decGrade();
    }
    catch(const std::exception & e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}

