#include "watch.h"

Watch sWatch;

void Watch::Update() {
   ucSeconds++;
   fSecondsChanged = 1;
   if (6 == ucSeconds) {
      ucSeconds = 0;
      ucMinutes++;
      fMinutesChanged = 1;
   }
}

