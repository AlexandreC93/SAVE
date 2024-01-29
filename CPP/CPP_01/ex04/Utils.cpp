#include "Utils.hpp"

Utils::Utils(std::string filename) : m_inFile(filename)
{
    this->m_outFile = this->m_inFile + ".replace";
}

Utils::~Utils()
{
}

void Utils::replace(std::string toFind, std::string replace)
{
    std::ifstream ifs(this->m_inFile.c_str());
    if (!ifs)
    {
        std::cerr << "Error: cant open input file." << std::endl;
        exit(EXIT_FAILURE);
    }
    std::string content;
    if (!std::getline(ifs, content, '\0'))
    {
        std::cerr << "Error: Cant read input file." << std::endl;
        ifs.close();
        exit(EXIT_FAILURE);
    }
    ifs.close();
    size_t pos = content.find(toFind);
    while (pos != std::string::npos)
    {
        content.erase(pos, toFind.length());
        content.insert(pos, replace);
        pos = content.find(toFind, pos + replace.length());
    }
    std::ofstream ofs(this->m_outFile.c_str());
    if (!ofs)
    {
        std::cerr << "Error: Cant open output file." << std::endl;
        exit(EXIT_FAILURE);
    }
    ofs << content;
    ofs.close();
}
