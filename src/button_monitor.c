#include "button_monitor.h"

// Inicializando botões A e B
void setup_buttons()
{
    gpio_init(BTN_A);
    gpio_set_dir(BTN_A, GPIO_IN);
    gpio_pull_up(BTN_A);

    gpio_init(BTN_B);
    gpio_set_dir(BTN_B, GPIO_IN);
    gpio_pull_up(BTN_B);
}

// Lendo o estado dos botões e armazenando em uma struct e retornando-a
ButtonStates read_button_states()
{
    ButtonStates btn_states;
    btn_states.btn_a_state = gpio_get(BTN_A);
    btn_states.btn_b_state = gpio_get(BTN_B);
    return btn_states;
}