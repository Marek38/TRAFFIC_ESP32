#include "led.h"

#include "esp_log.h"


Led::Led()
{

}

Led::Led(gpio_num_t pin)
{
    m_pin = pin;
    gpio_reset_pin(m_pin);
    gpio_set_direction(m_pin, GPIO_MODE_INPUT_OUTPUT);
}


void Led::on()
{

    gpio_set_level(m_pin, 1);
}

void Led::off()
{
    gpio_set_level(m_pin, 0);
}

void Led::toggle()
{
    int state = gpio_get_level(m_pin);
    state = !state;
    gpio_set_level(m_pin,state);
}



// void Led::greenPedestrian()
// {
//     if (a_ped_conn == Connection::TO_GROUND &&b_ped_conn == Connection::TO_GROUND)
//     ESP_LOGI(TAG, "Traffic switched to green for PEDESTRIANS");
    
//     {
//         gpio_set_level(a_ped_pin, 1);
//         gpio_set_level(b_ped_pin, 0);
//     }
//     else
//     {
//         gpio_set_level(a_ped_pin, 0);
//         gpio_set_level(b_ped_pin, 1);
//     }
//     vTaskdelay(pedTime);
// }


// void Led::redPedestrian()
// {
//     if (a_ped_conn == Connection::TO_GROUND &&b_ped_conn == Connection::TO_GROUND)
//     ESP_LOGI(TAG, "Traffic switched to red for PEDESTRIANS");
    
//     {
//         gpio_set_level(a_ped_pin, 0);
//         gpio_set_level(b_ped_pin, 1);
//     }
//     else
//     {
//         gpio_set_level(a_ped_pin, 1);
//         gpio_set_level(b_ped_pin, 0);
//     }
//     delay(pedTime);
// }
