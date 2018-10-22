#pragma once

#include "hitable.h"

class hitable_list: public hitable {
    public: 
        hitable_list() {}
        hitable_list(hitable **l, int n) {list_size = n; list = l;}
        virtual bool hit(const ray& r, float tmin, float tmax, hit_record& rec) const;
        hitable ** list;
        int list_size;
};

bool hitable_list::hit(const ray& r, float tmin, float tmax, hit_record& rec)const {
    hit_record tep_rec;
    bool hit_anything = false;
    double closest_so_fat = tmax;
    
    for(int i = 0; i < list_size; i++)
    {
        if (list[i]->hit(r, tmin, closest_so_fat, tep_rec)) {
            hit_anything = true;
            closest_so_fat = tep_rec.t;
            rec = tep_rec;
        }
    }
    return hit_anything;
}