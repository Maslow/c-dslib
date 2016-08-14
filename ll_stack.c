
#include "linked_list.c"

typedef linked_list_t ll_stack_t;

void lls_push(ll_stack_t *l, void *pd) { ll_insert_at(l, pd, 0); }

void *lls_pop(ll_stack_t *l) { return ll_remove_at(l, 0); }

void *lls_top(ll_stack_t *l) {
  if (l->head == NULL)
    return NULL;
  return l->head->pd;
}
