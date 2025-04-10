#ifndef WEB_SERVER_H
#define WEB_SERVER_H

#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lwip/netif.h"
#include "lwip/tcp.h"
#include "lwip/pbuf.h"

char WIFI_SSID[64];
char WIFI_PASSWORD[64];

void input_wifi_data(char *wifi_name, char *wifi_password);
static err_t tcp_server_accept_connectcion(void *arg, struct tcp_pcb *newpcb, err_t err);
static err_t tcp_server_recv_data(void *arg, struct tcp_pcb *tpcb, struct pbuf *package, err_t err);

#endif