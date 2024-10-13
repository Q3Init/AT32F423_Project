#include "led.h"
#include "at32f423_wk_config.h"
#include "wk_system.h"

void led_mainfunction(void)
{
    gpio_bits_toggle(GPIOD, LED1_PIN);
}

