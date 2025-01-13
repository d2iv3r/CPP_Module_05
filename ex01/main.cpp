# include "Bureaucrat.hpp"
# include "Form.hpp"

int main()
{
    try
    {
        Form f("form1", 100, 100);
        std::cout << f << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Form f("form2", 50, 80);
        Bureaucrat b("Ahmed", 50);
        f.beSigned(b);
        std::cout << f << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Form f("form4", 30, 50);
        Bureaucrat b("Ahmed", 55);
        b.signForm(f);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Form f("form4", 30, 50);
        Bureaucrat b("Ahmed", 25);
        b.signForm(f);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}
