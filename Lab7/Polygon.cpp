/* 
 * File:   Polygon.cpp
 * Author: kwonhong
 * 
 * Created on November 29, 2013, 4:39 PM
 */

#include "Polygon.h"

Polygon::Polygon (string _name, string _colour, float _xcen, float _ycen,
            t_point *_relVertex, int _npoint) 
              : Shape (_name, _colour, _xcen, _ycen) {
   
   //dynamically allocating memory for relVertex pointer
   relVertex = new t_point[_npoint];
           
   for (int i = 0; i < _npoint; i++) {
      relVertex[i].x = _relVertex[i].x;
      relVertex[i].y = _relVertex[i].y;
   }        
   npoint = _npoint;
}


Polygon::~Polygon () {
    delete relVertex; // deleting dynamically allocated memory
}


void Polygon::print () const {
   Shape::print();
   
   cout << "polygon";
   
   for (int i = 0; i < npoint; i++) {
      cout << " (" << getXcen() + relVertex[i].x << "," << getYcen()+ relVertex[i].y << ")";
   }
   cout << endl;
}


void Polygon::scale (float scaleFac) {
    // scale every relative points
    for (int i = 0; i < npoint; i++) {
      relVertex[i].x *= scaleFac;
      relVertex[i].y *= scaleFac;
   }
}


float Polygon::computeArea () const {
 
   float area = 0;
   int j = npoint - 1;
   
   //formula to find the area of the polygon
   for (int i = 0; i<npoint; i++) {
       area = area + ((relVertex[j].x+relVertex[i].x) * (relVertex[j].y-relVertex[i].y));
       j = i; 
   }
   
   return area/2;
}


float Polygon::computePerimeter () const {
   float perimeter = 0;
   float sideLength;
   int endIndex;
   t_point dist;
   
   //compute the length of edges and add up
   for (int i = 0; i < npoint; i++) {
      endIndex = (i + 1) % npoint;
      dist = getVecBetweenPoints (relVertex[i], relVertex[endIndex]);
      sideLength = sqrt (dist.x * dist.x + dist.y * dist.y);
      perimeter += sideLength;
   }
   return perimeter;
}


void Polygon::draw (easygl* window) const {

   t_point *coords = new t_point[npoint];  
   //storing actual location of each points by adding center of the polygon to relative points
   for (int i = 0; i < npoint; i++) {
      coords[i].x = getXcen() + relVertex[i].x;
      coords[i].y = getYcen() + relVertex[i].y;
   }
   
   window->gl_setcolor(getColour());
   window->gl_fillpoly(coords, npoint);
   
   delete coords;
}


bool Polygon::pointInside (float x, float y) const {
   t_point click;
   click.x = x - getXcen();
   click.y = y - getYcen();
   
   t_point vecOfSide;
   float distanceAlongVector, yDistance;
   int endIndex;
   int sidesToLeft = 0;
   
   for (int istart = 0; istart < npoint; istart++) {
      endIndex = (istart + 1) % npoint; // Next vertex after istart
      vecOfSide = getVecBetweenPoints (relVertex[istart], relVertex[endIndex]);
      yDistance = (click.y - relVertex[istart].y);
      if (vecOfSide.y != 0) {
          distanceAlongVector = yDistance / vecOfSide.y;
      }
      else if (yDistance == 0) {
          distanceAlongVector = 0;
      }
      else {
          distanceAlongVector = 1e10; // Really infinity, but this is big enough
      }
      
      if (distanceAlongVector >= 0 && distanceAlongVector < 1) {
         float xIntersection = relVertex[istart].x + vecOfSide.x * distanceAlongVector;
         if (xIntersection <= click.x ) 
             sidesToLeft++;
      }
   }
   
   return (sidesToLeft == 1);
}



// Private helper functions below.  

// Return the (x,y) vector between start and end points.
t_point Polygon::getVecBetweenPoints (t_point start, t_point end) const {
   t_point vec;
   vec.x = end.x - start.x;
   vec.y = end.y - start.y;
   return (vec);
}

