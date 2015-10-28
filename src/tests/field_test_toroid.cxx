#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include "SolenoidField.h"
#include "ToroidField.h"
#include "CLHEP/Units/SystemOfUnits.h"

int main( int argc, char **argv )
{
   using namespace clas12::mag;

   ToroidField field;

   TVector3 val;
   TVector3 x;

   for(int i = 0; i< 18; i++) {
      x.SetMagThetaPhi(300.0,5.0*CLHEP::degree, i*20.0*CLHEP::degree);
      val = field.GetField(x);
      std::cout << " At " ; x.Print();
      std::cout << " B is "; val.Print();
   }

   for(int i = 0; i< 10; i++) {
      x.SetXYZ(50.0,0.0,100.0+50.0*i);
      val = field.GetField(x);
      std::cout << " At " ; x.Print();
      std::cout << " B is "; val.Print();
   }

   return 0;
}

