#ifndef TACO_PARSING_FILEREADER_HPP
#define TACO_PARSING_FILEREADER_HPP

#include "archive.hpp"
#include <istream>
#include <string>

template <typename T> class FileReader
{
  public:
    FileReader(const T &path);
    float read_float()
    {
        float value;
        m_marker_file->read((char *)&value, sizeof(value));
        return value;
    }

    int read_int()
    {
        int value;
        m_marker_file->read((char *)&value, sizeof(value));
        return value;
    }

    short read_short()
    {
        short value;
        m_marker_file->read((char *)&value, sizeof(value));
        return value;
    }

    char read_byte()
    {
        char value;
        m_marker_file->read(&value, sizeof(value));
        return value;
    }

    bool eof() { return m_marker_file->peek() == EOF; }

    std::unique_ptr<std::istream> &get_file() { return m_marker_file; }

  private:
    std::unique_ptr<std::istream> m_marker_file;
};

template <> FileReader<std::string>::FileReader(const std::string &path);
template <> FileReader<AFile>::FileReader(const AFile &path);

#endif // !TACO_PARSING_FILEREADER_HPP
