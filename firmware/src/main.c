/*
 * Sablefin Soil Probe — SSP-4 application entry point.
 * Released firmware for the STM32L072 sensor board.
 */
#include "board.h"
#include "sensors.h"
#include "lora.h"

int main(void) {
    board_init();
    sensors_init();
    lora_init();

    for (;;) {
        sensor_sample_t sample;
        sensors_read(&sample);
        lora_queue_sample(&sample);
        board_sleep_until_next_window();
    }
}
