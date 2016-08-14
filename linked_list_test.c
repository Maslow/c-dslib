
#include "linked_list.c"
#include "util.c"
#include <stdio.h>

int main(int argc, char const *argv[]) {
  linked_list_t list;
  linked_list_t *pl = &list;
  ll_init(pl);
  if (ll_empty(pl))
    printf("\tlist is empty\n");

  ll_insert_at(pl, new_double(3.14), 0);
  ll_insert_at(pl, new_double(4.14), 0);
  ll_insert_at(pl, new_double(5.14), 0);

  while (pl->len) {
    double *d = ll_remove_at(pl, 0);
    if (d != NULL)
      printf("\t%lf ", *d);
    free(d);
  }
  printf("\n");
  return 0;
}
