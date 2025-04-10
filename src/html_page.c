#include "html_page.h"

void write_html(char *html_buffer, size_t buffer_size, float temperature, ButtonStates btn_states)
{
    snprintf(html_buffer, buffer_size,
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html\r\n"
        "\r\n"
        "<!DOCTYPE html>\n"
        "<html>\n"
        "<head>\n"
        "    <meta http-equiv=\"refresh\" content=\"1\">\n"
        "    <title>Status dos Sensores</title>\n"
        "    <style>\n"
        "        body { font-family: Arial, sans-serif; text-align: center; }\n"
        "    </style>\n"
        "</head>\n"
        "<body>\n"
        "    <h1>Dados em tempo real</h1>\n"
        "    <p>Temperatura: %.2f °C</p>\n"
        "    <p>Botão A: %s</p>\n"
        "    <p>Botão B: %s</p>\n"
        "</body>\n"
        "</html>\n",
        temperature,
        btn_states.btn_a_state ? "Pressionado" : "Solto",
        btn_states.btn_b_state ? "Pressionado" : "Solto"
    );
}
