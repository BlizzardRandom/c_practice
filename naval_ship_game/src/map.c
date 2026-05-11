#include "map.h"
#include <stdint.h>
#include <stdlib.h>

#define DEFAULT_MAP_WIDTH 5
#define DEFAULT_MAP_HEIGHT 4

static int gen_random(const int max, const int min) {
  return rand() % (max + 1 - min) + min;
}

uint8_t check_value(uint8_t byte, COORDS_VALUES value) {
  return (byte >> value) & 1;
}

uint8_t toggle_value(uint8_t byte, COORDS_VALUES value) {
  return byte ^ (1 << value);
}

static void populate_random_mines(MAP_DEF *map) {
#define MAX_MINES 5
  int mines_placed = 0;
  while (mines_placed != MAX_MINES) {
    int pos = gen_random((map->cols * map->rows - 1), 0);
    int x_pos = pos / map->rows;
    int y_pos = pos - (x_pos * map->rows);

    MAP_COORDS *calculated_mine = &map->coords[y_pos][x_pos];

    if (check_value(calculated_mine->opts, hasMine) == TRUE)
      continue;

    calculated_mine->opts = toggle_value(calculated_mine->opts, hasMine);
    mines_placed++;
  }

  map->currentMines = MAX_MINES;
}

// public
MAP_DEF *create_new_map(const int *width, const int *height) {
  uint8_t w = DEFAULT_MAP_WIDTH, h = DEFAULT_MAP_HEIGHT;

  if (width != NULL && (*width > 0 && *width < 9))
    w = *width;

  if (height != NULL && (*height > 0 && *height < 9))
    h = *height;

  // rows
  MAP_COORDS **matrix = calloc(h, sizeof(MAP_COORDS *));

  // cols
  for (int i = 0; i < h; i++)
    matrix[i] = calloc(w, sizeof(MAP_COORDS));

  MAP_DEF *map_def = malloc(sizeof(MAP_DEF));
  map_def->cols = w;
  map_def->rows = h;
  map_def->coords = matrix;
  map_def->lifesRemaining = 2;

  populate_random_mines(map_def);
  return map_def;
}

void free_map(MAP_DEF *map) {
  for (int i = 0; i < map->rows; i++)
    free(map->coords[i]);

  free(map->coords);
  free(map);
}
