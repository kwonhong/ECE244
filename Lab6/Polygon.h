/* 
 * File:   Polygon.h
 * Author: kwonhong
 *
 * Created on November 29, 2013, 4:39 PM
 */

#ifndef POLYGON_H
#define	POLYGON_H

#include "Shape.h"
#include "easygl.h"
#include <iostream>
#include <cmath>

class Polygon : public Shape {
private:
   // t_point is a structure defined in easygl.h.  It has two members,
   // .x and .y, storing a 2D point.  We store 3 points in relVertex; 
   // each is the (x,y) offset of one triangle vertex from the shape 
   // center.
   t_point *relVertex;   
   int npoint;
   
   // Private helper functions.
   t_point getVecBetweenPoints (t_point start, t_point end) const;
   float getCrossProduct (t_point vec1, t_point vec2) const;
   
public:
   Polygon (string _name, string _colour, float _xcen, float _ycen,
             t_point *_relVertex, int _npoint);
   
   // virtual keyword is optional in all the function declarations below, since
   // the base class Shape already declared them virtual. But it is good 
   // practice to repeat it again here, for clarity.
   virtual ~Polygon();
   
   
   virtual void print () const;
   virtual void scale (float scaleFac);
   virtual float computeArea () const;
   virtual float computePerimeter () const;
   virtual void draw (easygl* window) const;
   virtual bool pointInside (float x, float y) const;
};


#endif	/* POLYGON_H */

