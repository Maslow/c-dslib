
#include "ll_queue.c"
#include "util.c"
#include <stdio.h>

int main(int argc, char const *argv[]) {
  ll_queue_t queue;
  ll_queue_t *q = &queue;
  ll_init(q);
  if (ll_empty(q))
    printf("\tlist is empty\n");

  llq_push(q, new_double(3.14));
  llq_push(q, new_double(4.14));
  llq_push(q, new_double(5.14));

  while (q->len) {
    double *d = llq_pop(q);
    if (d != NULL)
      printf("\t%lf ", *d);
    free(d);
  }
  printf("\n");
  return 0;
}
