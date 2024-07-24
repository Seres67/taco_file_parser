#include "marker.hpp"
#include <algorithm>
#include <cstring>
#include <format>
#include <help.hpp>
#include <iostream>
#include <parse.hpp>

void trail(char path[])
{
    FileParser<Trail> parser(path);
    parser.parse_file();
    auto trails = parser.get_data();
    int count = 0;
    for (auto &trail_section : trails) {
        auto points = trail_section.get_points();
        std::sort(points.begin(), points.end(),
                  [](auto a, auto b) { return a.x > b.x; });
        for (auto &point : points) {
            std::cout << "(" << std::format("{}", point.x) << "; "
                      << std::format("{}", point.y) << "; "
                      << std::format("{}", point.z) << ")" << std::endl;
            ++count;
        }
        std::cout << "===========================" << std::endl;
    }
    std::cout << "found " << count << " points" << std::endl;
}

void marker(char path[])
{
    FileParser<Marker> parser(path);
    parser.parse_file();
    auto markers = parser.get_data();
    int count = 0;
    for (auto &trail_section : markers) {
        auto points = trail_section.get_points();
        std::sort(points.begin(), points.end(),
                  [](auto a, auto b) { return a.x > b.x; });
        for (auto &point : points) {
            std::cout << "(" << std::format("{}", point.x) << "; "
                      << std::format("{}", point.y) << "; "
                      << std::format("{}", point.z) << ")" << std::endl;
            ++count;
        }
        std::cout << "===========================" << std::endl;
    }
    std::cout << "found " << count << " points" << std::endl;
}

int main(int ac, char *av[])
{
    if (ac != 3) {
        help();
    }
    if (!strcmp(av[1], "--trail")) {
        trail(av[2]);
    } else if (!strcmp(av[1], "--marker")) {
        marker(av[2]);
    }
}
