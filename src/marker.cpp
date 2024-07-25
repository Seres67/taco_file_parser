#include <marker.hpp>

Marker::Marker(const std::string &icon_path, float icon_scale)
    : m_icon_path(icon_path), m_icon_scale(icon_scale)
{
}

void Marker::add_point(Point3D point) { m_points.emplace_back(point); }

std::vector<Point3D> Marker::get_points() { return m_points; }
