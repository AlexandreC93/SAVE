#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <limits>
#include <iomanip>
#include <climits>
#include <sstream>

class Contact
{
    private:
        int         m_index;
        std::string m_firstName;
        std::string m_lastName;
        std::string m_nickName;
        std::string m_phoneNumber;
        std::string m_darkestSecret;

        std::string m_printLen(std::string str);
        std::string m_getInput(std::string str);
    public:
    Contact();
    ~Contact();
    void    start(void);
    void    view(int index);
    void    display(int index);
    void    setIndex(int i);
};

#endif