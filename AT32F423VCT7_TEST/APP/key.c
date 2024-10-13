#include "key.h"
#include "at32f423_wk_config.h"
#include "wk_system.h"

static uint8_t key_signal = FALSE;

void key_mainfunction(void)
{
    if (key_signal == TRUE) {
        key_signal = FALSE;
        gpio_bits_toggle(GPIOD,LED2_PIN);
    }
}

void set_key_signal(void)
{
    key_signal = TRUE;
}
