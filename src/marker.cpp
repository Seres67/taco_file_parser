#include <marker.hpp>

void Marker::add_point(Point3D point) { m_points.emplace_back(point); }

std::vector<Point3D> Marker::get_points() { return m_points; }
