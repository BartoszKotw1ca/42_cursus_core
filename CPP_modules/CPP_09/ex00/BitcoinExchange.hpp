#pragma once

#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <list>

class BitcoinExchange
{
    public:
        BitcoinExchange( void );
        ~BitcoinExchange( void );
        BitcoinExchange & operator = ( const BitcoinExchange & other );
        BitcoinExchange( const BitcoinExchange & other );
        void save_infile( std::string infile_na );
        void save_data( std::string data );
        void print_data( int a );
        void print_info( void );
    private:
        std::list<std::list<std::string> > _infile_list;
        std::list<std::list<std::string> > _data_list;
} ;
