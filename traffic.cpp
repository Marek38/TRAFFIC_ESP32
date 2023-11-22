#include "traffic.h"
#include "led.h"


Traffic::Traffic(Led green_led, Led orange_led, Led red_led)
{
    green = green_led;
    orange = orange_led;
    red = red_led;
};

void Traffic::CarRed()
{
    red.on();
    orange.off();
    green.off();
}
void Traffic::CarOrange()
{
    red.off();
    orange.on();
    green.off();
}
void Traffic::CarGreen()
{
    red.off();
    green.on();
    orange.off();
}