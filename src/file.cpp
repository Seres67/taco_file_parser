#include <file.hpp>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>

template <>
FileReader<std::string>::FileReader(const std::string &path)
    : m_marker_file(std::make_unique<std::ifstream>(path, std::ios::binary))
{
}

template <>
FileReader<AFile>::FileReader(const AFile &file)
    : m_marker_file(std::make_unique<std::stringstream>(file.file_content))

{
}
