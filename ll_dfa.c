
#include "linked_list.c"
#include "util.c"
#include <stdlib.h>

#define DFA_SE -1

typedef linked_list_t lld_s_t;
typedef linked_list_t lld_e_t;
typedef linked_list_t lld_sa_t;
typedef linked_list_t lld_g_t;
typedef linked_list_t lld_g_status_t;

typedef struct {
  lld_s_t S;
  lld_e_t E;
  int s0;
  lld_sa_t S_a;
  lld_g_t G;
} ll_dfa_t;

typedef struct {
  char c;
  int s;
} lld_g_pair_t;

void lld_init(ll_dfa_t *d, int s0) {
  d->s0 = s0;
  ll_init(&(d->S));
  ll_init(&(d->E));
  ll_init(&(d->S_a));
  ll_init(&(d->G));
}

int lld_s_exist(lld_s_t *l, int s) {
  if (ll_empty(l))
    return 0;
  ll_node_t *p = l->head;
  while (p != NULL) {
    int *i = (int *)p->pd;
    if (*i == s)
      return 1;
    p = p->next;
  }
  return 0;
}

int lld_e_exist(lld_e_t *l, char c) {
  if (ll_empty(l))
    return 0;
  ll_node_t *p = l->head;
  while (p != NULL) {
    char *i = (char *)p->pd;
    if (*i == c)
      return 1;
    p = p->next;
  }
  return 0;
}

lld_g_status_t *lld_g_exist(lld_g_t *g, int s) {
  if (ll_empty(g))
    return NULL;
  ll_node_t *p = g->head;
  while (p != NULL) {
    int *i = (int *)p->pd;
    if (*i == s)
      return p->pd;
    p = p->next;
  }
  return NULL;
}

lld_g_pair_t *lld_g_status_exist(lld_g_status_t *l, char c) {
  if (ll_empty(l))
    return NULL;
  ll_node_t *p = l->head;
  while (p != NULL) {
    lld_g_pair_t *temp = p->pd;
    if (temp->c == c)
      return p->pd;
  }
  return NULL;
}

int lld_g_get(lld_g_t *g, int s, char c) {
  lld_g_status_t *g_s = lld_g_exist(g, s);
  if (g_s == NULL)
    return DFA_SE;
  lld_g_pair_t *p = lld_g_status_exist(g_s, c);
  if (p != NULL)
    return p->s;
  return DFA_SE;
}

void lld_s_insert(ll_dfa_t *d, int s, int isSa) {
  lld_s_t *l = &(d->S);
  if (lld_s_exist(l, s))
    return;
  ll_insert_at(l, new_int(s), l->len);
  if (isSa) {
    linked_list_t *la = &(d->S_a);
    ll_insert_at(la, new_int(s), l->len);
  }
}

void lld_e_insert(lld_e_t *l, char c) {
  if (lld_e_exist(l, c))
    return;
  ll_insert_at(l, new_char(c), l->len);
}

void ll_g_insert(lld_g_t *g, int s_in, char c, int s_out) {
  lld_g_status_t *g_s;
  lld_g_pair_t *pair;
  g_s = lld_g_exist(g, s_in);
  if (g_s == NULL) {
    g_s = (lld_g_status_t *)malloc(sizeof(linked_list_t));
    ll_init(g_s);
    ll_insert_at(g, g_s, g->len);
  }
  pair = lld_g_status_exist(g_s, c);
  if (pair == NULL) {
    pair = (lld_g_pair_t *)malloc(sizeof(lld_g_pair_t));
    pair->c = c;
    pair->s = s_out;
    ll_insert_at(g_s, (void *)pair, g_s->len);
  }
}
