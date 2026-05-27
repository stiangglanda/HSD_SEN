#ifndef CIRCLE_H
#define CIRCLE_H
#include "GraphicObject.h"

//Spezielle Klasse 'Circle' abgeleitet von 'GraphicObject'
class Circle : public GraphicObject
{
public:
  //to do
    Circle();
    ~Circle();

    void SetRadius(size_t const rad);

    //ueberschreiben von Draw
    void Draw() const;
 
private:
   size_t mRadius = 0;
};

#endif //CIRCLE_H
