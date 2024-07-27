#ifndef TACO_FILE_PARSER_ARCHIVE_HPP
#define TACO_FILE_PARSER_ARCHIVE_HPP

#include <string>
#include <vector>

struct AFile
{
    std::string content;
    std::string name;
};

struct MarkerFile
{
    std::string name;
    std::string content;
};

struct TrailFile
{
    std::string name;
    std::string content;
};

class ArchiveReader
{
  public:
    ArchiveReader(const std::string &path);
    std::vector<AFile> get_files();
    std::vector<struct AFile> get_marker_files();
    std::vector<struct AFile> get_trail_files();

  private:
    std::vector<struct AFile> m_files;
    std::vector<struct MarkerFile> m_marker_files;
    std::vector<struct TrailFile> m_trail_files;
};

#endif // !TACO_FILE_PARSER_ARCHIVE_HPP
