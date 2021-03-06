#ifdef __CINT__

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

#pragma link C++ nestedclass;

#pragma link C++ namespace clas12;
#pragma link C++ namespace clas12::hits;

#pragma link C++ class clas12::hits::DCWire+;
#pragma link C++ class clas12::hits::DCSuperLayer+;

#pragma link C++ class std::map<clas12::hits::DCSuperLayer, TH2Poly*>+;
#pragma link C++ class std::unordered_map<clas12::hits::DCSuperLayer, TH2Poly*>+;

#pragma link C++ class clas12::hits::TriggerEvent+;
#pragma link C++ class clas12::hits::HTCCHitsEvent+;
#pragma link C++ class clas12::hits::ECHitsEvent+;
#pragma link C++ class clas12::hits::DCHitsEvent+;
#pragma link C++ class clas12::hits::RCHitsEvent+;
#pragma link C++ class clas12::hits::ForwardHitMask+;
#pragma link C++ class clas12::hits::EventHitMask+;
#pragma link C++ class clas12::hits::SVTEvent+;

#pragma link C++ class clas12::hits::RecoilScintHit+;
#pragma link C++ class clas12::hits::PhotonHit+;
#pragma link C++ class clas12::hits::PhotonCounterHit+;
#pragma link C++ class clas12::hits::RecoilScintEvent+;
#pragma link C++ class clas12::hits::ScintChannelHit+;
#pragma link C++ class clas12::hits::RHHit+;

#pragma link C++ class clas12::hits::ADCHit+;
#pragma link C++ class clas12::hits::TDCHit+;
#pragma link C++ class clas12::hits::FlashADCHit+;

#pragma link C++ function clas12::hits::P_j_ion_pair(double, int, double);
#pragma link C++ function clas12::hits::does_step_create_ion_pair(double, int, double);

#pragma link C++ class clas12::hits::ParticleHit+;
#pragma link C++ class clas12::hits::DriftChamberIonPairHit+;
#pragma link C++ class clas12::hits::DriftChamberParticleHit+;
#pragma link C++ class clas12::hits::RecoilChamberParticleHit+;

#pragma link C++ class std::map<int,clas12::hits::PhotonCounterHit>+;
#pragma link C++ class std::map<int,clas12::hits::ScintChannelHit>+;

#pragma link C++ class clas12::hits::CLAS12HitsEvent+;
 
 
#endif
