#ifndef TACO_PARSING_MARKER_HPP
#define TACO_PARSING_MARKER_HPP

#include <point.hpp>
#include <string>
#include <vector>

class MarkerType
{
  public:
    MarkerType();

  private:
    float m_icon_scale;
    std::string m_icon_path;
};

using MarkerType = struct MarkerType;

class POI
{
  public:
    POI(int map_id, float x, float y, float z, const MarkerType &type);
    POI(Point3D pos, const MarkerType &type);
    Point3D get_pos();

  private:
    Point3D m_pos;
    MarkerType m_type;
};

using POI = struct POI;

class Marker
{
  public:
    Marker();
    void add_point(const POI &point);
    std::vector<POI> get_points();

  private:
    std::vector<POI> m_pois;
    std::string m_pack_creator;
    std::string m_markers_name;
    std::string m_name;
};

#endif // !TACO_PARSING_MARKER_HPP
