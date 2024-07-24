#include <cstdint>
#include <file.hpp>
#include <fstream>
#include <iostream>
#include <stdlib.h>

FileReader::FileReader(const std::string &path)
    : m_marker_file(path, std::ios::binary)
{
    if (m_marker_file.is_open()) {
        std::cout << "opened file " << path << std::endl;
    }
}

float FileReader::read_float()
{
    float value;
    m_marker_file.read((char *)&value, sizeof(value));
    return value;
}

int FileReader::read_int()
{
    int value;
    m_marker_file.read((char *)&value, sizeof(value));
    return value;
}

short FileReader::read_short()
{
    short value;
    m_marker_file.read((char *)&value, sizeof(value));
    return value;
}

char FileReader::read_byte()
{
    char value;
    m_marker_file.read(&value, sizeof(value));
    return value;
}

bool FileReader::eof() { return m_marker_file.peek() == EOF; }

std::ifstream &FileReader::get_file() { return m_marker_file; }
