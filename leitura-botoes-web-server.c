#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

/*
#include "pico/stdlib.h" // Biblioteca padrão do Pico SDK para GPIO, temporização e funções básicas
#include "hardware/adc.h" // Biblioteca para uso do ADC (Conversor Analógico-Digital) para leitura de temperatura
#include "pico/cyw43_arch.h" // Biblioteca para controle do chip Wi-Fi CYW43 usado no Raspberry Pi Pico W
#include <stdio.h> // Biblioteca padrão para entrada/saída, usada para printf e outras funções de I/O
#include <string.h> // Biblioteca padrão para manipulação de strings, usada em strstr, memcpy, etc.
#include <stdlib.h> // Biblioteca padrão para alocação de memória dinâmica e outras funções utilitárias
#include "lwip/pbuf.h" // Biblioteca do LWIP para manipulação de buffers de pacotes TCP/IP
#include "lwip/tcp.h" // Biblioteca do LWIP para controle e manipulação de conexões TCP
#include "lwip/netif.h" // Biblioteca do LWIP para manipulação de interfaces de rede e endereços IP
*/


int main()
{
    stdio_init_all();
    
    // Initialise the Wi-Fi chip
    if (cyw43_arch_init()) {
        printf("Wi-Fi init failed\n");
        return -1;
    }

    // Example to turn on the Pico W LED
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}
