#include <stdint.h>
#include <stddef.h>
#include <limine.h>

#include "drivers/graphics.h"

// Note: Some functions in here and most of linker.ld and GNUmakefile come from limine bare bones tutorial in the osdev wiki

static volatile struct limine_framebuffer_request framebuffer_request = {
    .id = LIMINE_FRAMEBUFFER_REQUEST,
    .revision = 0
};
 
// DO NOT REMOVE THESE FUNCTIONS!

void *memcpy(void *dest, const void *src, size_t n) {
    uint8_t *pdest = (uint8_t *)dest;
    const uint8_t *psrc = (const uint8_t *)src;
 
    for (size_t i = 0; i < n; i++) {
        pdest[i] = psrc[i];
    }
 
    return dest;
}
 
void *memset(void *s, int c, size_t n) {
    uint8_t *p = (uint8_t *)s;
 
    for (size_t i = 0; i < n; i++) {
        p[i] = (uint8_t)c;
    }
 
    return s;
}
 
void *memmove(void *dest, const void *src, size_t n) {
    uint8_t *pdest = (uint8_t *)dest;
    const uint8_t *psrc = (const uint8_t *)src;
 
    if (src > dest) {
        for (size_t i = 0; i < n; i++) {
            pdest[i] = psrc[i];
        }
    } else if (src < dest) {
        for (size_t i = n; i > 0; i--) {
            pdest[i-1] = psrc[i-1];
        }
    }
 
    return dest;
}
 
int memcmp(const void *s1, const void *s2, size_t n) {
    const uint8_t *p1 = (const uint8_t *)s1;
    const uint8_t *p2 = (const uint8_t *)s2;
 
    for (size_t i = 0; i < n; i++) {
        if (p1[i] != p2[i]) {
            return p1[i] < p2[i] ? -1 : 1;
        }
    }
 
    return 0;
}
 
void hang() {
    asm ("cli");
    for (;;) {
        asm ("hlt");
    }
}
 
void _start() {
    // Here we take everything we need from limine
    if (framebuffer_request.response == NULL
     || framebuffer_request.response->framebuffer_count < 1) {
        hang();
    }
    struct limine_framebuffer *framebuffer = framebuffer_request.response->framebuffers[0];

    // Calling a bunch of initialization functions
    initFb(framebuffer->width, framebuffer->height, framebuffer->pitch, framebuffer->address); // frame buffer init 
    println("Initialized frame buffer");
    
    
    // Everything's done
    hang();
}