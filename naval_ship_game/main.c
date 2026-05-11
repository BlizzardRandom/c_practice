
#include "src/map.h"
#include "src/selection.h"
#include <stdio.h>
#include <stdlib.h>
int main(void) {
  int opt;
  char *helper_text;
  MAP_DEF *board = create_new_map(NULL, NULL);

  do {
    printf("Select one of the following options: \n"
           "1) New game\n"
           "2) Explore\n"
           "3) Display map\n"
           "4) Credits\n"
           "5) GET OUT!\n");

    scanf("%d", &opt);

    switch (opt) {
    case 1:
      free_map(board);
      board = create_new_map(NULL, NULL);
      printf("Generated new board\n");
      break;
    case 2:
      helper_text = select_point(board);
      printf("> %s\n", helper_text);
      break;
    case 3:
      printf("opt 3\n");
      break;
    case 4:
      printf("opt 4\n");
      break;
    case 5:
      free_map(board);
      printf("Quitting \n");
      break;
    default:
      printf("Invalid option.\n");
      opt = 0;
    }
  } while (opt != 5);

  return EXIT_SUCCESS;
}
