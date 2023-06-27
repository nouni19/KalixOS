#include "stdbool.h"

#pragma once

void pixel(uint64_t x, uint64_t y, uint64_t color);
void printc(uint32_t x, uint32_t y, char c, uint64_t color, uint64_t background_color, bool color_background);
uint32_t prints(uint32_t x, uint32_t y, char *str, uint64_t color, uint64_t background_color, bool color_background);
void println(char *str);
void initFb(uint64_t width, uint64_t height, uint64_t pitch, uint32_t *ptr);