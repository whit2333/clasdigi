#ifndef TriggerEvent_HH
#define TriggerEvent_HH

#include "TObject.h"
namespace clas12 {

   namespace hits {

      class TriggerEvent : public TObject {

         public:
            int              fRunNumber;
            int              fEventNumber;
            int              fTrigType;

            double           fTrigTime;

         public:
            TriggerEvent();
            virtual ~TriggerEvent();

            void Clear(Option_t * opt = "" ) ;
            void Print(Option_t * opt = "" ) const ;

         ClassDef(TriggerEvent,1)
      };

   }

}

#endif

