#include "point.hpp"
#include <trail.hpp>
#include <vector>

void Trail::add_point(Point3D point) { m_points.emplace_back(point); }

std::vector<Point3D> Trail::get_points() { return m_points; }
