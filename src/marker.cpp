#include "point.hpp"
#include <marker.hpp>

Marker::Marker() {}

void Marker::add_point(const POI &point) { m_pois.emplace_back(point); }

std::vector<POI> Marker::get_points() { return m_pois; }

POI::POI(int map_id, float x, float y, float z, const MarkerType &type)
    : m_pos({map_id, x, y, z}), m_type(type)
{
}

POI::POI(Point3D pos, const MarkerType &type) : m_pos(pos), m_type(type) {}

Point3D POI::get_pos() { return m_pos; }
