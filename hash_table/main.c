#include "./src/hash_table.h"
#include <stdio.h>

int main() {
  ht_hash_table *ht = ht_new();

  ht_insert(ht, "hello", "world");
  ht_insert(ht, "foo", "bar");
  ht_insert(ht, "hash", "table");

  printf("Search: %s\n", ht_search(ht, "hello"));
  printf("Search: %s\n", ht_search(ht, "foo"));
  printf("Search: %s\n", ht_search(ht, "hash"));

  // seg fault lol
  ht_delete(ht, "hello");
  printf("Search after delete: %s\n", ht_search(ht, "hello"));

  ht_del_hash_table(ht);
  return 0;
}
