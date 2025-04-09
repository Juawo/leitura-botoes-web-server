#ifndef HTML_PAGE_H
#define HTML_PAGE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pico/stdlib.h"
#include "button_monitor.h"

char* write_html(char *html_buffer, size_t buffer_size, float temperature, ButtonStates btns_states);

#endif