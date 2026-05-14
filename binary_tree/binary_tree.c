
#include "binary_tree.h"
#include <stdint.h>
#include <stdlib.h>

// NOTE: Private
static Node *recursive_traversal(Node *node, uint32_t v) {
  if (node->value == v)
    return node;

  if (node->left != NULL)
    return recursive_traversal(node->left, v);

  if (node->right != NULL)
    return recursive_traversal(node->right, v);

  return NULL;
}

// NOTE: PUBLIC
inline Node *create_node(uint32_t val) {
  Node *new_node = malloc(sizeof(Node));
  new_node->value = val;
  return new_node;
}

BinaryTree *init_binary_tree(uint32_t v) {
  BinaryTree *tree = malloc(sizeof(BinaryTree));
  tree->root = create_node(v);
  return tree;
}

Node *add_adjacent_node(Node *node, uint32_t v) {
  if (node->left != NULL && node->right != NULL)
    return NULL;

  Node *new_node = create_node(v);

  if (node->left == NULL)
    node->left = new_node;
  else
    node->right = new_node;

  return new_node;
}

Node *get_node_by_val(BinaryTree *tree, uint32_t val) {
  return recursive_traversal(tree->root, val);
}

static void free_everything(Node *node) {
  if (node->left != NULL)
    free_everything(node->left);

  if (node->right != NULL)
    free_everything(node->right);

  free(node);
  return;
}
void free_tree(BinaryTree *tree) {
  free_everything(tree->root);
  free(tree);
}
