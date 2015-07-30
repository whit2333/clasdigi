#include "ThrownEvent.h"
#include <iostream>
#include <iomanip>


clas12::sim::ThrownEvent::ThrownEvent(int ch) : fChannel(ch)
{ } 
//______________________________________________________________________________

clas12::sim::ThrownEvent::ThrownEvent(int cr, int sl, int ch) : 
   fCrate(cr), fSlot(sl), fChannel(ch)
{ } 
//______________________________________________________________________________

clas12::sim::ThrownEvent::~ThrownEvent()
{ } 
//______________________________________________________________________________

void clas12::sim::ThrownEvent::Print(Option_t * opt) const
{
   std::cout 
      << "ThrownEvent"
      << "(ch=" << std::setw(4) << std::left << fChannel 
      << ",sl=" << std::setw(4) << std::left << fSlot
      << ",cr=" << std::setw(4) << std::left << fCrate
      << ") = (" 
      << "tag=" << std::setw(4) << std::left << fTag
      << ",num=" << std::setw(4) << std::left << fNum
      << ", " << clas12::ToString(fDetector)
      << ")"
      << "\n";
} 
//______________________________________________________________________________



