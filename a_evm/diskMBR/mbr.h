#ifndef SCOMPUTER_MBR_H
#define SCOMPUTER_MBR_H

#include <inttypes.h>
//http://ru.osdev.wikia.com/wiki/Адресация_CHS

typedef struct {
    uint16_t sector : 6;
    uint16_t cylinder : 10;
    uint8_t head : 4;
} tCHS;//20 bit

typedef struct {
    uint16_t sector : 6;
    uint16_t cylinder : 10;
    uint8_t head;
} tLARGE;//24 bit

typedef struct {
    uint32_t head : 4;
    uint32_t sector : 8;
    uint32_t cylinder : 16;
} tIDECHS;//28 bit

typedef uint32_t tLBA;//32 bit

#endif //SCOMPUTER_MBR_H
