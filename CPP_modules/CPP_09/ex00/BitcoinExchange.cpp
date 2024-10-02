#include "BitcoinExchange.hpp"

BitcoinExchange :: BitcoinExchange ( void ) {}

BitcoinExchange :: ~BitcoinExchange ( void ) {}

BitcoinExchange :: BitcoinExchange ( const BitcoinExchange & other )
{
    this->_data_vec = other._data_vec;
    this->_infile_vec = other._infile_vec;
}

BitcoinExchange & BitcoinExchange :: operator=(const BitcoinExchange & other )
{
    if ( this != &other )
    {
        this->_data_vec = other._data_vec;
        this->_infile_vec = other._infile_vec;
    }
    return *this;
}

void BitcoinExchange :: save_infile ( std::string infile_na )
{
    std::ifstream infile(infile_na.c_str());
    if (!infile.is_open())
    {
        std::cerr << "Nie można otworzyć pliku!" << std::endl;
        exit(1);
    }

    std::string line;
    while (std::getline(infile, line))
    {
        std::stringstream ss(line);
        std::string cell;
        std::vector<std::string> row;
        while (std::getline(ss, cell, '|'))
            row.push_back(cell);
        _infile_vec.push_back(row);
    }
} 

void BitcoinExchange :: save_data( std::string data )
{
    std::ifstream infile(data.c_str());
    if (!infile.is_open())
    {
        std::cerr << "Nie można otworzyć pliku!" << std::endl;
        exit(1);
    }

    std::string line;
    while (std::getline(infile, line))
    {
        std::stringstream ss(line);
        std::string cell;
        std::vector<std::string> row;
        while (std::getline(ss, cell, '|'))
            row.push_back(cell);
        _data_vec.push_back(row);
    }
}

void BitcoinExchange :: print_data( int a )
{
    std::vector<std::vector<std::string> >* data;
    if (a == 1)
        data = &this->_infile_vec;
    else
        data = &this->_data_vec;

    for (std::vector<std::vector<std::string> >::const_iterator row = data->begin(); row != data->end(); ++row)
    {
        {
            try
            {
                std::cout << row->at(0) << " " << row->at(1);
            }
            catch(const std::exception& e)
            {
                std::string a = e.what();
                if (a == "vector::_M_range_check: __n (which is 1) >= this->size() (which is 1)")
                    std::cout << "Error: bad input -> " << row->at(0);
            }
        }
        std::cout << std::endl;
    }
}

void BitcoinExchange :: print_info( void )
{
    std::vector<std::vector<std::string> > *data = &this->_infile_vec;
    for (std::vector<std::vector<std::string> > ::const_iterator row = data->begin() + 1; row != data->end(); row ++)
    {
        std::string input_date = row->at(0);
        std::vector<std::vector<std::string> > *data1 = &this->_data_vec;
        std::string closest_date;
        for (std::vector<std::vector<std::string> > ::const_iterator row1 = data1->begin(); row1 != data1->end(); row1 ++)
        {
            std::string db_date = row1->at(0);
            if (input_date == db_date)
            {
                closest_date = input_date;
                break;
            }
            if (db_date <= input_date && db_date > closest_date)
                closest_date = db_date;
        }
        try
        {
            if (atof(row->at(1).c_str()) < 0)
            {
                std::cout << "Error: not a positive number." << std::endl;
                continue;
            }
            if (atof(row->at(1).c_str()) > 1000)
            {
                std::cout << "Erorr: too large a number." << std::endl;
                continue;
            }
        }
        catch(const std::exception &e)
        {
            closest_date = "";
        }
        
        if (!closest_date.empty())
        {
            float rate;
            for (std::vector<std::vector<std::string> > ::const_iterator row1 = data1->begin(); row1 != data1->end(); row1 ++)
            {
                if (row1->at(0) == closest_date)
                {
                    try
                    {
                        rate = std::atof(row1->at(1).c_str());
                    }
                    catch( std::exception &e)
                    {
                        rate = -1;
                        std::cout << e.what() << std::endl;
                    }
                    break;
                }
            }
            std::cout << row->at(0) << " => " << row->at(1) << " = " << (rate * atof(row->at(1).c_str())) << std::endl;
        }
        else
            std::cout << "Error: bad input => " << row->at(0) <<std::endl;
    }
}
