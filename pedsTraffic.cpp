#include "PedsTraffic.h"
#include "led.h"

PedsTraffic::PedsTraffic(Led HugeGreen,  Led HugeRed)
{
    PedestrianGreen = HugeGreen;
    PedestrianRed = HugeRed;
};

void PedsTraffic::PedGreen(){
    PedestrianRed.off();
    PedestrianGreen.on();
}

void PedsTraffic::PedRed(){
    PedestrianRed.on();
    PedestrianGreen.off();
}