#pragma once
#include "cross_platform_vector.h"

struct QuantityInfo{
    float air_mass;
    float liquid_mass;
    float solid_mass;
    Vec3F vec;
};
constexpr int size_cube = 30;

QuantityInfo * get(QuantityInfo * data,CubeCoord c);

inline bool is_in_axis_bounds(int val){
    return val >= 0 && val < size_cube;
}
inline bool is_valid_cube(CubeCoord c){
    return
        is_in_axis_bounds(c.x) &&
        is_in_axis_bounds(c.y) &&
        is_in_axis_bounds(c.z);
}
