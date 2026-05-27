#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "GraphicObject.h"

//Spezielle Klasse 'Rectangle' abgeleitet von 'GraphicObject'
class Rectangle : public GraphicObject
{
public:
   //to do
   Rectangle();
   ~Rectangle();

   //ueberschreiben von Draw
   void Draw() const;
private:
   size_t mWidth = 0;
   size_t mHeight = 0;
};

#endif //RECTANGLE_H
