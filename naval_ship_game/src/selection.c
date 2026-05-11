#include "map.h"
#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define CHAR_ROW 0
#define CHAR_COL 1

static int *listen_input(char *error) {
#define POS 2
#define UNICODE_A 101

  char *opt;
  printf("Enter your guess: ");
  scanf("%s", opt);

  int *positions = calloc(2, sizeof(int));

  for (int i = 0; i < POS; i++) {
    char *res = opt + i;
    if (res == NULL || *res == '\0')
      break;

    // A,B,C,D...I
    if (i == CHAR_ROW) {
      char upper = toupper(*res);
      int resUp = upper - UNICODE_A;

      if (resUp < 0 || resUp > 9) {
        error = "Invalid alphabetic selection\0";
        break;
      }

      positions[CHAR_ROW] = resUp;
      continue;
    }

    // 0,1,2,3...9
    char **errorChan;
    long r = strtol(res, errorChan, 10);
    if ((r < 0 || r > 9) || errorChan != NULL) {
      error = "Invalid number selection\0";
      break;
    }

    positions[CHAR_COL] = r;
  }

  return positions;
}

char *select_point(MAP_DEF *map) {
  char *error;
  int *pos = listen_input(error);

  if (error != NULL)
    return error;

  int col_hit = pos[CHAR_COL];
  int row_hit = pos[CHAR_ROW];

  if (col_hit >= map->cols)
    return "Exceeded map cols\0";

  if (row_hit >= map->rows)
    return "Exceeded map rows\0";

  MAP_COORDS coord = map->coords[row_hit][col_hit];
  uint8_t res = check_value(coord.opts, hasMine);
  toggle_value(coord.opts, isVisited);

  if (res == TRUE) {
    map->lifesRemaining = map->lifesRemaining - 1;
    return "You hitted a mine! -1 Life \0";
  }

  return "Hit, -1 Life \0";
}
