#include <iostream>
#include <fstream>
#include <vld.h>          //notwendig um den Visual Leak Detector zu verwenden
#include "SimpleClass.h"
using namespace std;

//Fehlerkonstanten
static string const cErrRead = "error reading from file: ";
static string const cFileName = "euro.txt";
static string const cErrOpen = "error open file: ";

int main()
{
  
}