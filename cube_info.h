#pragma once
#include "cube_color.h"
#include "cube_coords.h"
#include <cstdlib>
#include <vector>
#include <iostream>
#include <glm/common.hpp>
#include <glm/geometric.hpp>
#include <algorithm>
#include "glm/gtx/string_cast.hpp"

constexpr int SIDES_ON_CUBE = 6;

struct VectorAttraction{
    float attraction_force;
};
struct QuantityInfo{
    float air_mass;
    float liquid_mass;
    glm::vec3 vec;
    float mass(){
        return air_mass + liquid_mass;
    }
    void add(QuantityInfo addval){
        if(abs((this->mass() + addval.mass())) < 10e-20f){
            this->vec = glm::vec3(0,0,0);
        }
        else{
            this->vec = (this->vec * this->mass() + addval.vec * addval.mass()) / (this->mass() + addval.mass());
        }
        this->air_mass += addval.air_mass;
        this->liquid_mass += addval.liquid_mass;
        //this->air_mass = std::max(0.0f,this->air_mass);
        //this->liquid_mass = std::max(0.0f,this->liquid_mass);
        assert(this->air_mass >= 0);
        assert(this->liquid_mass >= 0);
    }
    void subtract(QuantityInfo subval){
        QuantityInfo add_neg_val = subval;
        add_neg_val.air_mass = - add_neg_val.air_mass;
        add_neg_val.liquid_mass = - add_neg_val.liquid_mass;
        this->add(add_neg_val);
    }
    void debug_print(){
        using namespace  std;
        cout << this->air_mass << endl;
        cout << this->liquid_mass << endl;
        cout << to_string(this->vec) << endl;
    }
};
struct CubeChangeInfo{
    VectorAttraction attract;
    QuantityInfo quantity_shift;
};
class CubeInfo{
public:
    QuantityInfo data;
    bool is_border;
public:
    CubeInfo(bool in_is_border=false);
    CubeChangeInfo get_bordering_quantity_vel(const CubeInfo & other_cube,glm::vec3 cube_direction);
    void update_velocity_global();
    RGBVal color();
    bool is_transparent();
    void debug_print(){
        if(is_border){
            std::cout << "bordernode";
        }
        else{
            data.debug_print();
        }
    }
};
