#ifndef TACO_PARSING_PARSE_HPP
#define TACO_PARSING_PARSE_HPP

#include "marker.hpp"
#include <file.hpp>
#include <iostream>
#include <pugixml.hpp>
#include <vector>

template <typename T> class FileParser
{
  public:
    FileParser(const std::string &path);
    bool parse_file();
    std::vector<T> get_data() { return m_data; }

  private:
    FileReader m_reader;
    int m_file_version;
    int m_map_id;
    std::vector<T> m_data;
};
template <> FileParser<Trail>::FileParser(const std::string &path);
template <> FileParser<Marker>::FileParser(const std::string &path);

template <> bool FileParser<Trail>::parse_file();

template <> bool FileParser<Marker>::parse_file();

#endif // !TACO_PARSING_PARSE_HPP
