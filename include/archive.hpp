#ifndef TACO_FILE_PARSER_ARCHIVE_HPP
#define TACO_FILE_PARSER_ARCHIVE_HPP

#include <string>
#include <vector>

struct AFile
{
    std::string file_content;
    std::string file_name;
};

class ArchiveReader
{
  public:
    ArchiveReader(const std::string &path);
    std::vector<AFile> get_files();

  private:
    std::vector<AFile> m_files;
};

#endif // !TACO_FILE_PARSER_ARCHIVE_HPP
