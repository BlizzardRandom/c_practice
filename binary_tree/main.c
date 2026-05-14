#include "binary_tree.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
int main(void) {
  int i = 0;

  printf("Init tree \n");
  BinaryTree *tree = init_binary_tree(0);

  printf("Init node 1\n");
  Node *nodeOne = add_adjacent_node(tree->root, ++i);
  assert(nodeOne != NULL);
  printf("node 1 val: %d\n", nodeOne->value);

  printf("Init node 2\n");
  Node *nodeTwo = add_adjacent_node(tree->root, ++i);
  assert(nodeTwo != NULL);
  printf("node 2 val: %d\n", nodeTwo->value);

  printf("Init node 3 (should be null)\n");
  assert(add_adjacent_node(tree->root, 0) == NULL);

  printf("searching val %d:\n", i - 1);
  Node *val = get_node_by_val(tree, i - 1);
  assert(val != NULL);
  printf("val was: %d\n", val->value);

  printf("Cleaning tree:\n");
  free_tree(tree);
  return EXIT_SUCCESS;
}
