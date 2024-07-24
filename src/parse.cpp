#include <file.hpp>
#include <iostream>
#include <marker.hpp>
#include <parse.hpp>

template <>
FileParser<Trail>::FileParser(const std::string &path) : m_reader(path)
{
    m_file_version = m_reader.read_int();
    if (m_file_version != 0)
        std::cout << "unsupported version " << m_file_version << std::endl;
    m_map_id = m_reader.read_int();
    std::cout << "got mapid " << m_map_id << std::endl;
}

template <>
FileParser<Marker>::FileParser(const std::string &path) : m_reader(path)
{
}

template <> bool FileParser<Trail>::parse_file()
{
    m_data.emplace_back();
    while (!m_reader.eof()) {
        float x = m_reader.read_float();
        float z = m_reader.read_float();
        float y = m_reader.read_float();
        if (x == 0 && y == 0 && z == 0) {
            m_data.emplace_back();
        }
        m_data.back().add_point({m_map_id, x, y, z});
    }
    return true;
}

template <> bool FileParser<Marker>::parse_file()
{
    m_data.emplace_back();
    pugi::xml_document doc;
    pugi::xml_parse_result r = doc.load(m_reader.get_file());
    pugi::xml_node content = doc.child("OverlayData").child("POIs");
    for (auto &poi : content) {
        if (strcmp(poi.name(), "POI"))
            continue;
        float x = poi.attribute("xpos").as_float();
        float y = poi.attribute("ypos").as_float();
        float z = poi.attribute("zpos").as_float();
        int mapid = poi.attribute("MapID").as_int();
        m_data.back().add_point({mapid, x, y, z});
    }
    return true;
}
