#pragma once

#include "led.h"


class Traffic
{

  private:
    Led green;
    Led orange;
    Led red;

  public:;
    Traffic(Led green_led, Led orange_led, Led red_led);
    void CarGreen();
    void CarOrange();
    void CarRed();
    // void greenPedestrian();
    // void redPedestrian();
};