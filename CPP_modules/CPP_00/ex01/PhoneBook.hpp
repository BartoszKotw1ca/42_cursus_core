#include <iostream>

#ifndef PHONEBOOK_CLASS_CPP
# define PHONEBOOK_CLASS_CPP

class Contact
{
public:
    std::string& tmp( void );
    std::string& first_name( void );
    std::string& last_name( void );
    std::string& nickname( void );
    std::string& phone_num( void );
    std::string& secret( void );
private:
    std::string _tmp;
    std::string _first_name;
    std::string _last_name;
    std::string _nickname;
    std::string _phone_num;
    std::string _secret;
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
