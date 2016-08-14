
#include "ll_stack.c"
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
  ll_stack_t stack;
  ll_stack_t *s = &stack;
  ll_init(s);
  if (ll_empty(s))
    printf("list is empty\n");

  lls_push(s, new_double(3.14));
  lls_push(s, new_double(4.14));
  lls_push(s, new_double(5.14));

  while (s->len) {
    double *d = lls_pop(s);
    if (d != NULL)
      printf("%lf\n", *d);
    free(d);
  }
  return 0;
}
