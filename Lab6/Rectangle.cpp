/* 
 * File:   Rectangle.cpp
 * Author: kwonhong
 * 
 * Created on November 26, 2013, 4:15 PM
 */

#include "Rectangle.h"

Rectangle::Rectangle (string _name, string _colour, float _xcen, float _ycen,
             float _width, float _height) : Shape (_name, _colour, _xcen, _ycen) {
 
        width = _width;
        height = _height;
}

Rectangle::~Rectangle () {
   // No dynamic memory to delete
}

void Rectangle::print () const {
   Shape::print();
   cout << "rectangle width: " << width << " height: " << height << endl;
}

void Rectangle::scale (float scaleFac) {
   
      width *= scaleFac;
      height *= scaleFac;
}

float Rectangle::computeArea () const {
    return height*width;
}

float Rectangle::computePerimeter () const {
    return 2*(height+width);
}

void Rectangle::draw (easygl* window) const {
   // Load up the data structure needed by easygl, and draw the triangle
   // using the easygl::draw_polygon call.
   t_point coords[4];  // This data type is in easygl_constants.h
   
   float x1 = getXcen()-width/2;
   float x2 = getXcen()+width/2;
   float y1 = getYcen()+height/2;
   float y2 = getYcen()-height/2;
   
   window->gl_setcolor(getColour());
   window->gl_fillrect(x1,y1,x2,y2);      

}

bool Rectangle::pointInside (float x, float y) const {
    if((( x <= (getXcen() + width/2)) && (x >= (getXcen() -width/2)))
                && ( (y <= (getYcen()+ height/2)) && (y >= (getYcen() -height/2)) ))
        return true;
}