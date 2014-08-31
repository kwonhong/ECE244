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
      // scale the radius by scaleFactor
      radius *= scaleFac;
}

float Circle::computeArea () const {
    // area of the circle
    return PI*radius*radius;
}

float Circle::computePerimeter () const {
    //parameter of the circle
    return PI*2*radius;
}

void Circle::draw (easygl* window) const {
   
   // drawing the circle with 'flllarc' function
   window->gl_setcolor(getColour());
   window->gl_fillarc(getXcen(), getYcen(), radius, 0, 360);     

}

bool Circle::pointInside (float x, float y) const {
    // using the pythagorus theorem, determine if the point clicked is within the Circle
    float x1 = getXcen()-x;
    float y1 = getYcen()-y;
    float s1 = sqrt (x1*x1 + y1*y1);
    
    if (s1 <= radius)
        return true;
    return false;
}
