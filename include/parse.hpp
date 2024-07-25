#ifndef TACO_PARSING_PARSE_HPP
#define TACO_PARSING_PARSE_HPP

#include "archive.hpp"
#include "marker.hpp"
#include "trail.hpp"
#include <file.hpp>
#include <pugixml.hpp>
#include <vector>

template <typename T> class StringParser
{
  public:
    StringParser(const AFile &file);
    bool parse_content();
    std::vector<T> get_data() { return m_data; }

  private:
    FileReader<AFile> m_reader;
    int m_file_version;
    int m_map_id;
    std::vector<T> m_data;
};
template <> StringParser<Trail>::StringParser(const AFile &path);
template <> StringParser<Marker>::StringParser(const AFile &path);

template <> bool StringParser<Trail>::parse_content();

template <> bool StringParser<Marker>::parse_content();

#endif // !TACO_PARSING_PARSE_HPP
