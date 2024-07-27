#include "trail.hpp"
#include <file.hpp>
#include <iostream>
#include <marker.hpp>
#include <parse.hpp>

template <>
StringParser<Trail>::StringParser(const AFile &path) : m_reader(path)
{
    std::cout << "trying file " << path.file_name << std::endl;
    m_file_version = m_reader.read_int();
    if (m_file_version != 0)
        std::cout << "unsupported version " << m_file_version << std::endl;
    m_map_id = m_reader.read_int();
    std::cout << "got mapid " << m_map_id << std::endl;
}

template <>
StringParser<Marker>::StringParser(const AFile &path) : m_reader(path)
{
    std::cout << "trying file " << path.file_name << std::endl;
}

template <> bool StringParser<Trail>::parse_content()
{
    m_data.emplace_back();
    while (!m_reader.eof()) {
        float x = m_reader.read_float();
        float z = m_reader.read_float();
        float y = m_reader.read_float();
        if (x == 0 && y == 0 && z == 0)
            m_data.emplace_back();
        m_data.back().add_point({m_map_id, x, y, z});
    }
    return true;
}

template <> bool StringParser<Marker>::parse_content()
{
    pugi::xml_document doc;
    pugi::xml_parse_result r = doc.load(*m_reader.get_file());
    pugi::xml_node data = doc.child("OverlayData");
    pugi::xml_node creator = data.child("MarkerCategory");
    pugi::xml_node markers_infos = data.child("MarkerCategory");
    std::string creator_name = creator.attribute("DisplayName").as_string();
    std::string marker_name =
        markers_infos.attribute("DisplayName").as_string();

    float scale;
    std::string iconFile;
    for (auto &child : markers_infos.children()) {
        for (auto &attr : child.attributes()) {
            if (!strcmp(attr.name(), "iconSize")) {
                scale = attr.as_float();
            } else if (!strcmp(attr.name(), "iconFile")) {
                iconFile = attr.as_string();
            }
        }
    }

    m_data.emplace_back(iconFile, scale);
    pugi::xml_node pois = data.child("POIs");
    for (auto &poi : pois) {
        if (!strcmp(poi.name(), "POI")) {
            float x = poi.attribute("xpos").as_float();
            float y = poi.attribute("ypos").as_float();
            float z = poi.attribute("zpos").as_float();
            int mapid = poi.attribute("MapID").as_int();
            std::string type = poi.attribute("type").as_int();
            m_data.back().add_point({mapid, x, y, z, type});
        } else if (!strcmp(poi.name(), "Trail")) {
        }
    }
    return true;
}
