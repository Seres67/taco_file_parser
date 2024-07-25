#include <archive.hpp>
#include <iostream>
#include <vector>
#include <zip.h>

ArchiveReader::ArchiveReader(const std::string &path)
{
    int error;
    zip_t *taco = zip_open(path.c_str(), 0, &error);
    if (!taco)
        std::cout << "error opening file" << std::endl;
    int fcount = zip_get_num_entries(taco, 0);
    for (int i = 0; i < fcount; ++i) {
        const char *name = zip_get_name(taco, i, 0);
        struct zip_stat stats;
        zip_stat_index(taco, i, 0, &stats);
        zip_file_t *file = zip_fopen_index(taco, i, 0);
        char *buffer = new char[stats.size];
        auto bytes_read = zip_fread(file, buffer, stats.size);
        zip_fclose(file);
        m_files.emplace_back(std::string(buffer, bytes_read), name);
    }
    zip_close(taco);
}

std::vector<AFile> ArchiveReader::get_files() { return m_files; }
