/* 
 * File:   Circle.cpp
 * Author: kwonhong
 * 
 * Created on November 29, 2013, 4:26 PM
 */

#include "Circle.h"

Circle::Circle (string _name, string _colour, float _xcen, float _ycen,
             float _radius) : Shape (_name, _colour, _xcen, _ycen) {
 
    radius = _radius;
}

Circle::~Circle () {
   // No dynamic memory to delete
}

void Circle::print () const {
   Shape::print();
   cout << "circle radius: " << radius << endl;
}

void Circle::scale (float scaleFac) {
   
      radius *= scaleFac;
}

float Circle::computeArea () const {
    return PI*radius*radius;
}

float Circle::computePerimeter () const {
    return PI*2*radius;
}

void Circle::draw (easygl* window) const {
   // Load up the data structure needed by easygl, and draw the triangle
   // using the easygl::draw_polygon call.
   
   window->gl_setcolor(getColour());
   window->gl_fillarc(getXcen(), getYcen(), radius, 0, 360);     

}

bool Circle::pointInside (float x, float y) const {
    float x1 = getXcen()-x;
    float y1 = getYcen()-y;
    float s1 = sqrt (x1*x1 + y1*y1);
    
    if (s1 <= radius)
        return true;
}