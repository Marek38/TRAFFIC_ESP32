/* Blink Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "sdkconfig.h"
#include "led.h"
#include "traffic.h"
#include "pedsTraffic.h"
#include <memory>
#include "button.h"

    int driveTime = 7500;
    int restTime = 5000;
    int prepareTime = 3000;
    int pedTime = 5000;
    // int pedResTime = 5000;

/* Use project configuration menu (idf.py menuconfig) to choose the GňPIO to blink,
   or you can edit the following line and set a number here.
*/
// static const gpio_num_t BLINK_GPIO_RED = GPIO_NUM_13;
// static const gpio_num_t BLINK_GPIO_ORANGE = GPIO_NUM_12;
// static const gpio_num_t BLINK_GPIO_GREEN = GPIO_NUM_14;


extern "C"
{
    void app_main(void)
    {
        Led redGPIO(GPIO_NUM_13); //red_auto
        Led orangeGPIO(GPIO_NUM_12); //yellow_auto
        Led greenGPIO(GPIO_NUM_14); //green_auto
        Led PedsGreenGPIO(GPIO_NUM_27); //green_auto
        Led PedsRedGPIO(GPIO_NUM_25); //green_auto
        Button ButtonGPIO(GPIO_NUM_26); //green_auto

        Traffic* traffic_control = new Traffic(greenGPIO, orangeGPIO, redGPIO);
        PedsTraffic* peds_traffic_control = new PedsTraffic(PedsGreenGPIO, PedsRedGPIO);


while (1)
{
        traffic_control->CarGreen();
        peds_traffic_control->PedRed();
        while (!ButtonGPIO.Button_pressed()) {
            vTaskDelay(1);

        }
        vTaskDelay(prepareTime / portTICK_PERIOD_MS);
        peds_traffic_control->PedRed();
        traffic_control->CarOrange();
        vTaskDelay(restTime / portTICK_PERIOD_MS);
        traffic_control->CarRed();
        vTaskDelay(restTime / portTICK_PERIOD_MS);
        peds_traffic_control->PedGreen();
        vTaskDelay(pedTime / portTICK_PERIOD_MS);
        peds_traffic_control->PedRed();
        vTaskDelay(restTime / portTICK_PERIOD_MS);
        traffic_control->CarOrange();
        vTaskDelay(restTime / portTICK_PERIOD_MS);
        traffic_control->CarGreen();
        vTaskDelay(restTime / portTICK_PERIOD_MS);


        
    }
}

        
}

