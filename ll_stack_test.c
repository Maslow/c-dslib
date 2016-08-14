
#include "ll_stack.c"
#include "util.c"
#include <stdio.h>

int main(int argc, char const *argv[]) {
  ll_stack_t stack;
  ll_stack_t *s = &stack;
  ll_init(s);
  if (ll_empty(s))
    printf("\tlist is empty\n");

  lls_push(s, new_double(3.14));
  lls_push(s, new_double(4.14));
  lls_push(s, new_double(5.14));

  while (s->len) {
    double *d = lls_pop(s);
    if (d != NULL)
      printf("\t%lf ", *d);
    free(d);
  }
  printf("\n");
  return 0;
}
