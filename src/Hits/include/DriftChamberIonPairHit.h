#ifndef DriftChamberIonPairHit_HH
#define DriftChamberIonPairHit_HH 1

#include "TObject.h"
#include "TLorentzVector.h"
#include "TMath.h"


namespace clas12 {

   namespace hits {

      double P_j_ion_pair(double y, int j=1, double k = 28.0/*1/cm*/);

      bool   does_step_create_ion_pair(double y, int j=1, double k = 28.0/*1/cm*/);

      class DriftChamberIonPairHit : public TObject {
         public : 
            double          fStepLength;   // Step length used to determine ion pair probabilty
            int             fPDGCode;      // PDG code of particle.
            TLorentzVector  fPosition;      // Location where ion pair was produced position and time 
            DriftChamberIonPairHit(double x = 0.0, double y = 0.0, double z = 0.0, double t = 0.0);
            virtual ~DriftChamberIonPairHit();
            void Print();

            ClassDef(DriftChamberIonPairHit,1)
      };

   }

}

#endif
