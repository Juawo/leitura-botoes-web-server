#include "web_server.h"
#include "temperature_sensor.h"
#include "button_monitor.h"
#include "html_page.h"

void input_wifi_data(char *wifi_name, char *wifi_password)
{
    printf("Digite o nome da rede Wi-Fi que deseja conectar : \n");
    scanf("%s", wifi_name);
    printf("Digite a senha da rede Wi-Fi que deseja conectar : \n OBS : Caso não tenha senha, digite NULL \n");
    scanf("%s", wifi_password);
    if(wifi_password == "NULL")
    {
        wifi_password = NULL;
    }
}

err_t tcp_server_accept_connectcion(void *arg, struct tcp_pcb *newpcb, err_t err)
{
    tcp_recv(newpcb, tcp_server_recv_data);
    return ERR_OK;
}

err_t tcp_server_recv_data(void *arg, struct tcp_pcb *tpcb, struct pbuf *package, err_t err)
{
    if(!package)
    {
        tcp_close(tpcb);
        tcp_recv(tpcb, NULL);
        return ERR_OK;
    }

    char *request = (char *)malloc(package->len + 1);
    memcpy(request, package->payload, package->len);
    request[package->len] = '\0';

    printf("Requisição : %s\n", request);

    float temperature = read_temperature_sensor();
    ButtonStates btn_states = read_button_states();

    char html[1024];
    write_html(&html, strlen(html), temperature, btn_states);

    tcp_write(tpcb, &html, strlen(html), TCP_WRITE_FLAG_COPY);
    tcp_output(tpcb);

    free(request);
    pbuf_free(package);

    return ERR_OK;
}
