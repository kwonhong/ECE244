/* 
 * File:   Rectangle.h
 * Author: kwonhong
 *
 * Created on November 26, 2013, 4:15 PM
 */

#ifndef RECTANGLE_H
#define	RECTANGLE_H

#include "Shape.h"
#include "easygl.h"
#include <iostream>
#include <cmath>

class Rectangle: public Shape {
public:
    Rectangle();
    Rectangle (string _name, string _colour, float _xcen, float _ycen,
            float xcoords, float ycoords);
    virtual ~Rectangle();
    virtual void print () const;
    virtual void scale (float scaleFac);
    virtual float computeArea () const;
    virtual float computePerimeter () const;
    virtual void draw (easygl* window) const;
    virtual bool pointInside (float x, float y) const; 


private:
    float width;
    float height;
};

#endif	



