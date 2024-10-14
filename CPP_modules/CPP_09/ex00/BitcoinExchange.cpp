#include "BitcoinExchange.hpp"

BitcoinExchange :: BitcoinExchange ( void ) {}

BitcoinExchange :: ~BitcoinExchange ( void ) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    this->_data_list = other._data_list;
    this->_infile_list = other._infile_list;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        this->_data_list = other._data_list;
        this->_infile_list = other._infile_list;
    }
    return *this;
}

void BitcoinExchange::save_infile(std::string infile_na)
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
        std::list<std::string> row;
        while (std::getline(ss, cell, '|'))
            row.push_back(cell);
        _infile_list.push_back(row);
    }
}

void BitcoinExchange::save_data(std::string data)
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
        std::list<std::string> row;
        while (std::getline(ss, cell, '|'))
            row.push_back(cell);
        _data_list.push_back(row);
    }
}

void BitcoinExchange::print_data(int a)
{
    std::list<std::list<std::string> > *data = (a == 1) ? &_infile_list : &_data_list;

    for (std::list<std::list<std::string> >::const_iterator row = data->begin(); row != data->end(); ++row)
    {
        try
        {
            std::list<std::string>::const_iterator it = row->begin();
            if (row->size() > 1)
            {
                std::cout << *it << " " << *(++it);
            }
        }
        catch (const std::exception &e)
        {
            std::cout << "Error: bad input -> " << e.what() << std::endl;
        }
        std::cout << std::endl;
    }
}

void BitcoinExchange::print_info(void)
{
    std::list<std::list<std::string> >::const_iterator row = _infile_list.begin();
    ++row;  // Przesunięcie na drugi element (jeśli istnieje)

    for (; row != _infile_list.end(); ++row)
    {
        std::string input_date = row->front();
        std::string closest_date;
        std::list<std::list<std::string> >::const_iterator row1 = _data_list.begin();

        for (; row1 != _data_list.end(); ++row1)
        {
            std::string db_date = row1->front();
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
            std::list<std::string>::const_iterator it = row->begin();
            ++it;
            if (it != row->end() && std::atof(it->c_str()) < 0)
            {
                std::cout << "Error: not a positive number." << std::endl;
                continue;
            }
            if (it != row->end() && std::atof(it->c_str()) > 1000)
            {
                std::cout << "Error: too large a number." << std::endl;
                continue;
            }
        }
        catch (const std::exception &e)
        {
            closest_date = "";
        }

        if (!closest_date.empty())
        {
            float rate = -1;
            for (row1 = _data_list.begin(); row1 != _data_list.end(); ++row1)
            {
                if (row1->front() == closest_date)
                {
                    try
                    {
                        std::list<std::string>::const_iterator it1 = row1->begin();
                        ++it1;
                        if (it1 != row1->end())
                        {
                            rate = std::atof(it1->c_str());
                        }
                    }
                    catch (const std::exception &e)
                    {
                        std::cout << e.what() << std::endl;
                    }
                    break;
                }
            }
            std::list<std::string>::const_iterator it = row->begin();
            ++it;
            std::cout << row->front() << " => " << *it << " = ";
            std::cout << (rate * std::atof(it->c_str())) << std::endl;
        }
        else
        {
            std::cout << "Error: bad input => " << row->front() << std::endl;
        }
    }
}
