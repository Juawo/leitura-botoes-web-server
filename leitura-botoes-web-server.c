#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "button_monitor.h"
#include "temperature_sensor.h"
#include "web_server.h"

int main()
{
    stdio_init_all();
    setup_buttons();
    setup_temperature_sensor();

    // Initialise the Wi-Fi chip
    if (cyw43_arch_init()) {
        printf("Wi-Fi init failed\n");
        return -1;
    }

    // Example to turn on the Pico W LED
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
    cyw43_arch_enable_sta_mode();

    printf("Conectando ao Wi-Fi ...\n");
    input_wifi_data(WIFI_SSID, WIFI_PASSWORD);
    while(cyw43_arch_wifi_connect_timeout_ms(WIFI_SSID, WIFI_PASSWORD, CYW43_AUTH_WPA2_AES_PSK, 20000))
    {
        printf("Falha ao conectar à rede : %s \n", WIFI_SSID);
        sleep_ms(100);
        return -1;
    }

    printf("Conectado à rede Wi-Fi! \n");

    if(netif_default)
    {
        printf("IP do dispositivo : %s\n", ipaddr_ntoa(&netif_default->ip_addr)); // Exibe o IP do dispositivo
    }
    


    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}
