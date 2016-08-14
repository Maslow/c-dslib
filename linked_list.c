
#include <stdlib.h>

typedef struct __ll_node_st {
  void *pd;
  struct __ll_node_st *next;
} ll_node_t;

typedef struct __ll_st {
  ll_node_t *head;
  ll_node_t *tail;
  size_t len;
} linked_list_t;

void ll_init(linked_list_t *l) {
  l->head = l->tail = NULL;
  l->len = 0;
}

int ll_empty(linked_list_t *l) { return !(l->len); }

int ll_insert_at(linked_list_t *l, void *pd, size_t pos) {
  ll_node_t *pn = (ll_node_t *)malloc(sizeof(ll_node_t));
  pn->pd = pd;
  pn->next = NULL;
  if (pos > l->len) {
    return 0;
  } else if (pos == 0) {
    pn->next = l->head;
    l->head = pn;
    if (l->len == 0)
      l->tail = l->head;
  } else if (pos == l->len) {
    l->tail->next = pn;
    l->tail = pn;
  } else {
    ll_node_t *prev = l->head;
    for (size_t i = 0; i < pos - 1; i++)
      prev = prev->next;

    pn->next = prev->next;
    prev->next = pn;
  }
  l->len++;
  return 1;
}

void *ll_remove_at(linked_list_t *l, size_t pos) {
  if (ll_empty(l) || pos > l->len - 1)
    return NULL;

  ll_node_t *p = NULL;
  if (pos == 0) {
    p = l->head;
    l->head = l->head->next;
    if (l->len == 1)
      l->tail = l->head;
  } else {
    ll_node_t *prev = l->head;
    for (size_t i = 0; i < pos - 1; i++)
      prev = prev->next;
    p = prev->next;
    prev->next = p->next;
    if (pos == l->len - 1)
      l->tail = prev->next;
  }
  l->len--;
  void *pd = p->pd;
  free(p);
  return pd;
}
