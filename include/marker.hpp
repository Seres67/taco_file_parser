#ifndef TACO_PARSING_MARKER_HPP
#define TACO_PARSING_MARKER_HPP

#include <point.hpp>
#include <vector>

class Marker
{
  public:
    Marker() = default;
    void add_point(Point3D point);
    std::vector<Point3D> get_points();

  private:
    std::vector<Point3D> m_points;
};

#endif // !TACO_PARSING_MARKER_HPP
