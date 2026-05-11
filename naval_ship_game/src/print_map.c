#include "map.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void print_map(MAP_DEF *map) {

  for (int r = 0; r < map->rows; r++) {

    int str_len = map->cols * map->rows;
    char *col_formation =
        calloc(str_len, sizeof(char));    // irredundant doing + sizeof char!
    for (int c = 0; c < map->cols; c++) { // c++ mentioned

      MAP_COORDS cord = map->coords[r][c];

      int hasMine = check_value(cord.opts, hasMine);
      int isVisited = check_value(cord.opts, isVisited);

      switch (isVisited) {
      case 1:
        if (hasMine)
          strcat(col_formation, "[~]\0");
        else
          strcat(col_formation, "[x]\0");
        break;

      case 0:
        strcat(col_formation, "[ ]\0");
        break;

      default:
        printf("isVisited is nor 1 or 0.... this shouldn't be happening\n");
        assert(isVisited != 1 && isVisited != 0);
      }
    }
    printf("%s\n", col_formation);
    free(col_formation);
  }
}
