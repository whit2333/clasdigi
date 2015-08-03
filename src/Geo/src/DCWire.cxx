#include "DCWire.h"
#include "TMath.h"


//______________________________________________________________________________

clas12::geo::DCWire::DCWire(int sec, int reg, int sl, int l, int w) : 
   fSector(sec), fRegion(reg), fSuperLayer(sl), fLayer(l), fWire(w) 
{ } 
//______________________________________________________________________________

clas12::geo::DCWire::~DCWire()
{ } 
//______________________________________________________________________________

CLHEP::Hep2Vector clas12::geo::ApplyRotation(CLHEP::Hep2Vector v, double angle)
{
   v.rotate(angle);
   return v;
}
//______________________________________________________________________________

std::vector<CLHEP::Hep2Vector> clas12::geo::RegionTrapPoints(int region)
{
   // returns the 8 points defining a trapezoid volume defined by the two 
   // endplates and the front and back windows.
   // The first point is "nose" point were the endplates meet 
   // closest to the z axis and furthest upstream towards the target.
   // The origin of the solid's  coordinate system is this first gaurd wire
   // in the midplane (used to define theta_min).
   using namespace clas12::geo::DC;
   using namespace CLHEP;

   int index = region-1;
   std::vector<CLHEP::Hep2Vector> points;
   if( index < 0 || index >= 3 )
   {
      std::cout << "clas12::geo::RegionTrapPoints(region=" << region << ") : Region out of range\n";
      return  points;
   }

   double RegionLength = FrontGap[index] + MidGap[index] + BackGap[index];
   RegionLength += 21.0*LayerSep.at( RegionSuperLayerIndex[index][0] ) ;
   RegionLength += 21.0*LayerSep.at( RegionSuperLayerIndex[index][1] ) ;

   // The mid plane cross section is a rectangle plus a right triangle. 
   // extra_back is the length of the triangle on the back window plane
   double extra_back = RegionLength*TMath::Tan(RegionTilt[index]);

   double l1 = EndPlateShortSideLength[index];
   double l2 = EndPlateLongSideLength[index];

   // This returns the nose angle (between two end plates) for the window when viewed normal to it
   double actual_plate_angle = WindowAngle( EndPlateAngle[index]/2.0 , RegionTilt[index] );

   // nose height cut from triangular tip.
   double nose_width  =  NoseWidthInside[index]/2.0;
   double nose_height =  nose_width/TMath::Tan(EndPlateAngle[index]/2.0);
   double nose_side   = TMath::Sqrt(nose_width*nose_width + nose_height*nose_height);

   double h1 = l1*TMath::Cos(actual_plate_angle);
   double x1 = l1*TMath::Sin(actual_plate_angle);
   double h2 = l2*TMath::Cos(actual_plate_angle);
   double x2 = l2*TMath::Sin(actual_plate_angle);

   std::cout << "Rough check : " << extra_back << " vs " << l2-l1 << std::endl;

   Hep2Vector p0(  nose_width, nose_height );
   Hep2Vector p1( -nose_width, nose_height );
   Hep2Vector p2( -x1,  h1);
   Hep2Vector p3(  x1,  h1);

   double dx = RegionLength*TMath::Tan( RegionTilt[index]  );

   Hep2Vector p4(  nose_width, nose_height-dx );
   Hep2Vector p5( -nose_width, nose_height-dx );
   Hep2Vector p6( -x2, h2-dx);
   Hep2Vector p7(  x2, h2-dx);

   points = { p1, p2, p3, p0, p5, p6, p7, p4 };

   return points;
}
//______________________________________________________________________________

double  clas12::geo::RegionTrapWidth(int region)
{

   int index = region-1;
   if( index < 0 || index >= 3 )
   {
      std::cout << "clas12::geo::RegionTrapWidth(region=" << region << ") : Region out of range\n";
      return  0.0;
   }
   using namespace clas12::geo::DC;
   double RegionLength = FrontGap[index] + MidGap[index] + BackGap[index];
   RegionLength += 21.0*LayerSep.at( RegionSuperLayerIndex[index][0] ) ;
   RegionLength += 21.0*LayerSep.at( RegionSuperLayerIndex[index][1] ) ;

   return RegionLength/2.0;
}
//______________________________________________________________________________

double clas12::geo::SuperLayerRefWire_z(int sl)
{
   using namespace clas12::geo::DC;
   int index = sl-1;
   return( DistanceToTarget[index]*TMath::Cos(ThetaMin[index]) );
}
//______________________________________________________________________________

double clas12::geo::SuperLayerRefWire_y(int sl)
{
   using namespace clas12::geo::DC;
   int index = sl-1;
   return( DistanceToTarget[index]*TMath::Sin(ThetaMin[index]) );
}
//______________________________________________________________________________

CLHEP::HepRotation clas12::geo::RegionRotation(int sec, int region)
{
   using namespace clas12::geo::DC;
   using namespace CLHEP;
   HepRotation  rot;
   rot.rotateX( - RegionTilt[region-1] );
   rot.rotateZ( SectorRotation[sec-1] );
   return rot;
}
//______________________________________________________________________________

CLHEP::Hep3Vector clas12::geo::RegionTranslation(int sec, int region)
{
   using namespace clas12::geo::DC;
   using namespace CLHEP;
   //HepRotation  rot;
   //rot.rotateZ( SectorRotation[sec-1] );
   CLHEP::Hep3Vector  vec(
         0.0,//SuperLayerRefWire_y(RegionSuperLayers[region-1][0]),
         RegionXOffset[region-1],
         SuperLayerRefWire_z(RegionSuperLayers[region-1][0])
         );
   vec.rotateZ( SectorRotation[sec-1] );
   //vec.transform(rot);
   return vec;
}
//______________________________________________________________________________

double  clas12::geo::WindowAngle(double th, double th_tilt)
{
   // The angle of the window where the endplate meets.
   using namespace clas12::geo::DC;
   using namespace CLHEP;
   Hep3Vector Y1(0,1.0,0);
   Hep3Vector X1(1,0,0);
   X1.setRThetaPhi(1.0,90*degree,90*degree - th);
   Hep3Vector dz(0,0,TMath::Tan(th_tilt)) ;
   std::cout << " Angle between Y and vector is " << X1.angle(Y1)/degree << std::endl;
   Hep3Vector X2  = X1 + dz;
   Hep3Vector Y2  = Y1 + dz;
   std::cout << " Now angle is " << X2.angle(Y2)/degree << std::endl;
   return X2.angle(Y2);
}
//______________________________________________________________________________

