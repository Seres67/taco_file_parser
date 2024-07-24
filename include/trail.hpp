#ifndef TACO_PARSING_TRAIL_HPP
#define TACO_PARSING_TRAIL_HPP

#include <point.hpp>
#include <vector>

class Trail
{
  public:
    Trail() = default;
    void add_point(Point3D point);
    std::vector<Point3D> get_points();

  private:
    int m_map_id;
    std::vector<Point3D> m_points;
};

#endif // !TACO_PARSING_TRAIL_HPP
