/* 
 * File:   Polygon.cpp
 * Author: kwonhong
 * 
 * Created on November 29, 2013, 4:39 PM
 */

#include "Polygon.h"

// Constructor. First set up base class (Shape), then store the 
// vertices, which are 3 (x,y) points giving offsets from the Shape center 
// to each triangle vertex.
Polygon::Polygon (string _name, string _colour, float _xcen, float _ycen,
            t_point *_relVertex, int _npoint) 
              : Shape (_name, _colour, _xcen, _ycen) {
   
   relVertex = new t_point[_npoint];
           
   for (int i = 0; i < _npoint; i++) {
      relVertex[i].x = _relVertex[i].x;
      relVertex[i].y = _relVertex[i].y;
   }        
   npoint = _npoint;
}


Polygon::~Polygon () {
    delete relVertex;
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
   for (int i = 0; i < npoint; i++) {
      relVertex[i].x *= scaleFac;
      relVertex[i].y *= scaleFac;
   }
}


float Polygon::computeArea () const {
   // 1/2 * base * height
   // The height requires some trigonometry to compute, for an arbitrary triangle.
   // Some manipulation gives a simpler formula to use in this case, which I use below.
   // Compute two vectors, from one vertex to each of the other two.
   // Then use the formula below to get area.
   float area = 0;
   int j = npoint - 1;
   
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
   
   for (int i = 0; i < npoint; i++) {
      endIndex = (i + 1) % npoint;
      dist = getVecBetweenPoints (relVertex[i], relVertex[endIndex]);
      sideLength = sqrt (dist.x * dist.x + dist.y * dist.y);
      perimeter += sideLength;
   }
   return perimeter;
}


void Polygon::draw (easygl* window) const {
   // Load up the data structure needed by easygl, and draw the triangle
   // using the easygl::draw_polygon call.
   t_point *coords = new t_point[npoint];  // This data type is in easygl_constants.h
   for (int i = 0; i < npoint; i++) {
      coords[i].x = getXcen() + relVertex[i].x;
      coords[i].y = getYcen() + relVertex[i].y;
   }
   
   window->gl_setcolor(getColour());
   window->gl_fillpoly(coords, npoint);
   
   delete coords;
}


bool Polygon::pointInside (float x, float y) const {
   // Make a point that corresponds to where you clicked. Since all my
   // vertices are relative to the triangle center, it is more convenient
   // to also shift the click point so it is an offset from the triangle 
   // center.
   t_point click;
   click.x = x - getXcen();
   click.y = y - getYcen();
   
   // The test is that a horizontal line (ray) from x = -infinity to the click point
   // will cross (intersect) only one side of triangle to the left of the 
   // click point.  If the point is above or below the triangle, the ray will not
   // intersect any triangle sides. If the point is to the left of the triangle
   // the ray will also not intersect any sides to the left of the point.
   // If the point is to the right of the triangle, the ray will intersect
   // two sides of the triangle to its left. Only if the point is inside the 
   // triangle will the ray intersect exactly one side to the left of the point.
   
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
      
      // We intersect this side if the distance (scaling) along the side vector to 
      // get to our "click" y point is between 0 and 1.  Count the first 
      // endpoint of the side as being part of the line (distanceAlongVector = 0)
      // but don't count the second endPoint; we'll intersect that point later 
      // when we check the next side.
      if (distanceAlongVector >= 0 && distanceAlongVector < 1) {
         float xIntersection = relVertex[istart].x + vecOfSide.x * distanceAlongVector;
         if (xIntersection <= click.x ) 
             sidesToLeft++;
      }
   }
   
   return (sidesToLeft == 1);
}



// Private helper functions below.  Working out triangle area etc. 
// requires some vector math, so these helper functions are useful.

// Return the (x,y) vector between start and end points.
t_point Polygon::getVecBetweenPoints (t_point start, t_point end) const {
   t_point vec;
   vec.x = end.x - start.x;
   vec.y = end.y - start.y;
   return (vec);
}


// Return vec1 x vec2, where vec1 and vec2 are 2D vectors, and 
// hence the cross product is a single (z-directed) number.
float Polygon::getCrossProduct (t_point vec1, t_point vec2) const {
   return (vec1.x * vec2.y - vec1.y * vec2.x);
}
