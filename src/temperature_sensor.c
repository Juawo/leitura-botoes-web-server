#include "temperature_sensor.h"

void setup_temperature_sensor()
{
    adc_init();
    adc_set_temp_sensor_enabled(true);
}

float read_temperature_sensor()
{
    adc_select_input(4);                                 // Seleciona o canal ADC 4
    uint16_t raw_value = adc_read();                     // Lê o valor bruto do ADC
    const float conversion_factor = 3.3f / (1 << 12);    // Fator de conversão para tensão
    float temperature = 27.0f - ((raw_value * conversion_factor) - 0.706f) / 0.001721f; // Converte para temperatura
    return temperature;
}