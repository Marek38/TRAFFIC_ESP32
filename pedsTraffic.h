#pragma once

#include "led.h"

class PedsTraffic
{

  private:
    Led PedestrianGreen;
    Led PedestrianRed;

  public:;
    PedsTraffic(Led PedestrianGreen, Led PedestrianRed);
    void PedGreen();
    void PedRed();
};