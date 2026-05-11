#include "map.h"
#include <stdint.h>
#include <stdio.h>
void print_map(MAP_DEF *map) {
  // displaying the coords. yes i know i can do this in the main loop when r=0
  // && asserting the cords with r-1... takes too much thinking! im dumb!

  printf("  --- %d mines left ---\n\n ", map->currentMines);
  for (int r = 0; r <= map->rows; r++) {
    printf("   %d", r);
  }

  printf("\n");

  for (int r = 0; r < map->rows; r++) {
    printf(" %c", r + 'A');
    for (int c = 0; c < map->cols; c++) { // c++ mentioned
      MAP_COORDS *cord = &map->coords[r][c];

      uint8_t check_m = check_value(cord->opts, hasMine);
      uint8_t chech_v = check_value(cord->opts, isVisited);

      if (chech_v) {
        if (check_m)
          printf(" [~]");
        else
          printf(" [x]");
      } else
        printf(" [ ]");
    }
    printf("\n");
  }
}
