#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stdint.h>
#pragma once

typedef uint8_t error_return;

static const error_return FAILURE = 1;
static const error_return SUCCESS = 0;

typedef struct node {
  struct node *left;
  struct node *right;
  uint32_t value;

} Node;

typedef struct {
  Node *root;
} BinaryTree;

// node methods
Node *add_adjacent_node(Node *node, uint32_t v);
Node *create_node(uint32_t val);

// tree methods
BinaryTree *init_binary_tree(uint32_t v);
Node *get_node_by_val(BinaryTree *tree, uint32_t val);
void free_tree(BinaryTree *tree);

#endif
