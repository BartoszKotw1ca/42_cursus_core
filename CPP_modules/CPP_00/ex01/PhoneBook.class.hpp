#include <iostream>

#ifndef PHONEBOOK_CLASS_CPP
# define PHONEBOOK_CLASS_CPP

class Contact
{
public:
    std::string tmp;
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_num;
    std::string secret;
} ;

class PhoneBook
{
public:
    int num_of_con;
    Contact contacts[8];
    PhoneBook( void );
    ~PhoneBook( void );
    void    add( void );
	void    search (void );
private:
	void    print_info(int i);
} ;

#endif
