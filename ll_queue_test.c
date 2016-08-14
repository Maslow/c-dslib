
#include "ll_queue.c"
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
  ll_queue_t queue;
  ll_queue_t *q = &queue;
  ll_init(q);
  if (ll_empty(q))
    printf("list is empty\n");

  llq_push(q, new_double(3.14));
  llq_push(q, new_double(4.14));
  llq_push(q, new_double(5.14));

  while (q->len) {
    double *d = llq_pop(q);
    if (d != NULL)
      printf("%lf\n", *d);
    free(d);
  }
  return 0;
}
