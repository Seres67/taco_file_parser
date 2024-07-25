#ifndef TACO_PARSING_MARKER_HPP
#define TACO_PARSING_MARKER_HPP

#include <point.hpp>
#include <string>
#include <vector>

class Marker
{
  public:
    Marker(const std::string &icon_path, float icon_scale);
    void add_point(Point3D point);
    std::vector<Point3D> get_points();

  private:
    std::vector<Point3D> m_points;
    float m_icon_scale;
    std::string m_icon_path;
    std::string m_pack_creator;
    std::string m_markers_name;
    std::string m_name;
};

#endif // !TACO_PARSING_MARKER_HPP
