#include <iostream>

#ifndef PHONEBOOK_CLASS_CPP
# define PHONEBOOK_CLASS_CPP

class PhoneBook
{
public:
    int num_of_con;
    std::string tmp[8];
    std::string first_name[9];
    std::string last_name[9];
    std::string nickname[9];
    std::string phone_num[9];
    std::string secret[9];
    PhoneBook( void );
    ~PhoneBook( void );
    void    add( void );
	void    search (void );
private:
	void    print_info(int i);
} ;

#endif
