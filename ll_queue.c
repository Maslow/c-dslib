
#include "linked_list.c"

typedef linked_list_t ll_queue_t;

void llq_push(ll_queue_t *l, void *pd) { ll_insert_at(l, pd, l->len); }

void *llq_pop(ll_queue_t *l) { return ll_remove_at(l, 0); }

void *llq_front(ll_queue_t *l) {
  if (l->head == NULL)
    return NULL;
  return l->head->pd;
}

void *llq_back(ll_queue_t *l) {
  if (l->tail == NULL)
    return NULL;
  return l->tail->pd;
}
