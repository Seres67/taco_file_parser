#include "archive.hpp"
#include "point.hpp"
#include "trail.hpp"
#include <format>
#include <help.hpp>
#include <iostream>
#include <marker.hpp>
#include <parse.hpp>
#include <string>

void taco(char path[])
{
    ArchiveReader ar(path);
    auto files = ar.get_marker_files();
    for (auto &marker_file : files) {
        StringParser<Marker> marker_parser(marker_file);
        marker_parser.parse_content();
    }
    for (auto &file : files) {
        if (file.name.find("trl") != std::string::npos) {
            StringParser<Trail> sp(file);
            sp.parse_content();
            std::vector<Trail> data = sp.get_data();
            for (Trail &d : data) {
                for (Point3D &point : d.get_points()) {
                    std::cout << "(" << std::format("{}", point.x) << "; "
                              << std::format("{}", point.y) << "; "
                              << std::format("{}", point.z) << ")" << std::endl;
                }
            }
        } else if (file.name.find("xml") != std::string::npos) {
            StringParser<Marker> sp(file);
            sp.parse_content();
            std::vector<Marker> data = sp.get_data();
            for (Marker &d : data) {
                for (POI &point : d.get_points()) {
                    Point3D pos = point.get_pos();
                    std::cout << "(" << std::format("{}", pos.x) << "; "
                              << std::format("{}", pos.y) << "; "
                              << std::format("{}", pos.z) << ")" << std::endl;
                }
            }
        }
    }
}

int main(int ac, char *av[])
{
    if (ac != 3) {
        help();
    }
    if (!strcmp(av[1], "--taco")) {
        taco(av[2]);
    }
}
