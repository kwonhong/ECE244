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
   
   t_point *relVertex;   // store all the relative Vertex
   int npoint; // number of points
   
   // Private helper functions.
   t_point getVecBetweenPoints (t_point start, t_point end) const;
   
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

