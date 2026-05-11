#ifndef MAP_H
#define MAP_H

#pragma once
#include <stdint.h>

#define TRUE 1
#define FALSE 0

typedef enum {
  isVisited = 0,
  hasMine = 1,
} COORDS_VALUES;

// tbh, 1byte for bool is overkill
// so. i'll do byteshifting
// 01234567
// 7) isVisited
// 6) hasMine
// 5-0) unused
typedef struct {
  uint8_t opts;
} MAP_COORDS;

typedef struct {
  uint8_t cols;
  uint8_t rows;

  MAP_COORDS **coords;
  uint8_t currentMines;
  uint8_t lifesRemaining;
  uint8_t cellsChecked;

} MAP_DEF;

MAP_DEF *create_new_map(const int *width, const int *height);
void free_map(MAP_DEF *map);

uint8_t check_value(uint8_t byte, COORDS_VALUES value);
uint8_t toggle_value(uint8_t byte, COORDS_VALUES value);
#endif
