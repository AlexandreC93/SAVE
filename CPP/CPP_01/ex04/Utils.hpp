#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>

class Utils
{
private:
    std::string m_inFile;
    std::string m_outFile;

public:
    Utils(std::string filename);
    ~Utils();
    void replace(std::string s1, std::string s2);
};

#endif