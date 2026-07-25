#include"geometry.h"
const double PI=3.14;
double circle_area(double r){
    return PI*r*r;
}

double triangle_area(double base,double height){
    return 0.5*base*height;
}

double rectangle_area(double w,double h){
    return w*h;
};