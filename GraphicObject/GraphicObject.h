#ifndef GRAPH_OBJECT_H
#define GRAPH_OBJECT_H
#include <string>
#include "Object.h"

//Basisklasse aller graphischen Objekte, abgeleitet von der Basis aller
//Basisklassen 'Object'
class GraphicObject : public Object
{
public:
   //to do
   GraphicObject(std::string const& text = "GRAPHIC_OBJEKT");
   /*virtual*/ ~GraphicObject();

   // auf Getter/Setter wird hier bewusst verzichtet !!!
   void MoveTo(int const xpos, int const ypos);
   void RotateTo(double const orient);

   virtual void Draw() const; // mit virtual wird diese Methode zur Laufzeit dynamisch gebunden.
   //einmal virtuell == immer virtuell, auch in allen abgeleitetten Klassen

protected:
   //in abgeleiteten Klassen kann auf diesen Member direkt zugegriffen werden!
   std::string mText;

private:
   //in abgeleiteten Klassen kann auf diese Member nicht direkt zugegriffen
   //werden!
   int mXPos = 0;
   int mYPos = 0;
   double mOrientation = 0.0;
};

#endif //GRAPH_OBJECT_H
