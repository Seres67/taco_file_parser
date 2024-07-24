#ifndef TACO_PARSING_FILEREADER_HPP
#define TACO_PARSING_FILEREADER_HPP

#include "trail.hpp"
#include <cstdint>
#include <fstream>
#include <string>
#include <vector>

class FileReader
{
  public:
    FileReader(const std::string &path);
    int read_int();
    short read_short();
    char read_byte();
    float read_float();
    bool eof();
    std::ifstream &get_file();

  private:
    std::ifstream m_marker_file;
    std::vector<Trail> m_trails;
};

#endif // !TACO_PARSING_FILEREADER_HPP
