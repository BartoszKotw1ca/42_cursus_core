#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm :: ShrubberyCreationForm ( const std::string target ) : AForm("tmp", 145, 137)
{
    std::cout << "ShrubberyCreationForm constructor!" << std::endl;
    std::ofstream file((target + "_shrubbery").c_str());
    if (file.is_open())
    {
        file << "                                                &&& &&  & &&\n";
        file << "                                          && &\\/&\\|& ()|/ @, &&\n";
        file << "                                          &\\/(/&/&||/& /_/)_&/\n";
        file << "                                       &() &\\/&|()|/&\\/ '%\" & ()\n";
        file << "                                      &_\\/&&_ |& |&&/&__%_/_& &&\n";
        file << "                           &&   && & &|&|\\/&\\/%%|&  || & &| & ()/ @, &&\n";
        file << "                                      ()&_---()&\\&\\|&&-&&--%---()~\n";
        file << "                                              &&     \\|||\n";
        file << "                                                      |||\n";
        file << "                                                      |||\n";
        file << "                                                      |||\n";
        file << "                                  , -=-~  .-^- _ \n";
        file << "                         &&& &&  & && \n";
        file << "                    && &\\/&\\|& ()|/ @, &&\n";
        file << "                &\\/(/&/&||/& /_/)_&/\n";
        file << "             &() &\\/&|()|/&\\/ '%\" & ()\n";
        file << "             &_\\/&&_ |& |&&/&__%_/_& &&\n";
        file << "&&   && & &|&|\\/&\\/%%|&  || & &| & ()/ @, &&\n";
        file << "   ()&_---()&\\&\\|&&-&&--%---()~\n";
        file << "          &&     \\|||\n";
        file << "                  |||\n";
        file << "                  |||\n";
        file << "                  |||\n";
        file << "       , -=-~  .-^- _ \n";
        file.close();
    }
    else
    {
        std::cerr << "Unable to open file" << std::endl;
    }
}

ShrubberyCreationForm & ShrubberyCreationForm :: operator= ( const ShrubberyCreationForm & other)
{
    if (this != &other)
    {
        AForm::operator=(other);
    }
    return (*this);
}

ShrubberyCreationForm :: ShrubberyCreationForm ( const ShrubberyCreationForm & other) : AForm(other)
{
    return ;
}

ShrubberyCreationForm :: ~ShrubberyCreationForm ( void )
{
    std::cout << "ShrubberyCreationForm dexonsturctr!" << std::endl;
}

void ShrubberyCreationForm :: executee ( void ) const
{
    std::cout << "Im the Shrubbery Creation Form !!!" << std::endl;
}
