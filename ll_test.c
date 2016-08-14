
#include "linked_list.c"
#include <stdio.h>

void show(ll_node_t *lln) {
  if (lln == NULL) {
    printf("\n");
    return;
  }
  printf("%lf ", *((double *)lln->pd));
  show(lln->next);
}

void *new_double(double d) {
  double *p = (double *)malloc(sizeof(double));
  *p = d;
  return (void *)p;
}

int main(int argc, char const *argv[]) {
  linked_list_t list;
  linked_list_t *pl = &list;
  ll_init(pl);
  if (ll_empty(pl))
    printf("list is empty\n");

  ll_push(pl, new_double(3.14));
  ll_push(pl, new_double(4.14));
  ll_push(pl, new_double(5.14));

  while (pl->len) {
    double *d = ll_pop(pl);
    if (d != NULL)
      printf("%lf\n", *d);
    free(d);
  }
  return 0;
}
