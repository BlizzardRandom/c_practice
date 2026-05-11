
#include "src/credits.h"
#include "src/map.h"
#include "src/print_map.h"
#include "src/selection.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand(time(NULL)); // for the randomness???
  int opt = 0;
  char *helper_text = NULL;
  MAP_DEF *board = create_new_map(NULL, NULL);

  do {
    printf("\n");
    printf("Select one of the following options: \n"
           "1) New game\n"
           "2) Explore\n"
           "3) Display map\n"
           "4) Credits\n"
           "5) GET OUT!\n");

    if (scanf("%d", &opt) != 1) {
      printf("Invalid input! Please enter a number.\n");
      int c;

      // putting a char it just sends "a\n"... so i need to clear the \n as
      // well....
      while ((c = getchar()) != '\n' && c != EOF)
        ;

      opt = 0;
    }

    // clear screen posix only i wont be doing macros for different
    // architectures
    // TODO: port to clang!!!
    printf("\e[1;1H\e[2J");
    printf("\n\n\n");

    switch (opt) {
    case 1:
      free_map(board);
      board = create_new_map(NULL, NULL);
      printf("Generated new board\n");
      break;
    case 2:
      if (board->lifesRemaining <= 0) {
        printf("\033[1;33mCannot continue until another game is initialized! "
               "You lost!\033[0m\n");
        break;
      }

      helper_text = select_point(board);
      if (helper_text != NULL)
        printf("> %s\n", helper_text);

      if (board->cellsChecked ==
              (board->cols * board->rows - board->currentMines) ||
          board->currentMines == 0) {
        printf("\033[32m\nYOU'VE WON!\033[0m\n");
        break;
      }

      if (board->lifesRemaining <= 0)
        printf("\033[31mGAME OVER! 0 lifes remaining!\033[0m\n");

      break;
    case 3:
      print_map(board);
      break;
    case 4:
      print_credits();
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
