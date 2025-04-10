#include "temperature_sensor.h"

void setup_temperature_sensor()
{
    adc_init();
    adc_set_temp_sensor_enabled(true);
}

float read_temperature_sensor()
{
    return 0.0f;
}