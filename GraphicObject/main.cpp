#include <vector>
//#include <vld.h>
#include <algorithm>
#include <iostream>
#include "GraphicObject.h"
#include "Circle.h"
#include "Rectangle.h"
using namespace std;

int main()
{
   //to do
   GraphicObject gObj;
   Circle circ;
   Circle* pCirc = new Circle;
   Rectangle rect;
   Rectangle* pRect = new Rectangle;

   circ.SetRadius(34);
   circ.MoveTo(23, 56); // Aufruf einer geerbten Methode
   rect.RotateTo(2.12); // Aufruf einer geerbten Methode

   circ.Draw();
   rect.Draw();

   cout << endl << endl << "container with value_type 'GraphicObject':" << endl;
   using TCont = vector<GraphicObject>;
   TCont cont;

   cont.push_back(circ);
   cont.push_back(rect);
   cont.push_back(*pCirc);
   cont.push_back(*pRect);
   cont.push_back(gObj);

   cout << "draw graphic objects in vector:" << endl;
   for (auto const& elem : cont) { elem.Draw(); }
   cont.clear();

   cout << endl << endl << "container with value_type 'Circle':" << endl;
   using TCircleCont = vector<Circle>;
   TCircleCont circCont{circ, *pCirc /*rect*/ /*gObj*/};

   cout << "draw circle objects in vector:" << endl;
   for_each(circCont.cbegin(), circCont.cend(), [](auto const& c) { c.Draw(); });
   circCont.clear();

   cout << endl << endl << "container with value_type 'GraphicObject*':" << endl;
   using TGraphCont = vector<GraphicObject*>;
   TGraphCont graphCont{&circ, pCirc, &rect, pRect};

   //Statischer Datentyp von graphObj = GraphObject* => festgelegt zur Compilezeit
   //Dynamischer Datentyp von graphObj = Circle* => festgelegt zur Laufzeit (könnte auch Rectangle* sein)
   GraphicObject* graphObj = new Circle;
   graphCont.push_back(graphObj);
   GraphicObject* pGraph = new Rectangle;
   graphCont.push_back(pGraph);

   cout << "draw graphic objects in vector:" << endl;
   for_each(graphCont.cbegin(), graphCont.cend(), [](auto c) { c->Draw(); });
   circCont.clear();

   delete pCirc; pCirc = nullptr;
   delete pRect; pRect = nullptr;
   delete graphObj; graphObj = nullptr;
   delete pGraph; pGraph = nullptr;
}
