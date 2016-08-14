
#include <stdio.h>

#define MAXLENGTH 1024

struct stack {
  int data[MAXLENGTH];
  int top;
};

void init(struct stack *p) { p->top = -1; }

int push(struct stack *s, int i) {
  if (s->top == MAXLENGTH - 1) {
    return -1;
  }
  s->data[++(s->top)] = i;
  return 0;
}

int pop(struct stack *s, int *i) {
  if (s->top == -1) {
    return -1;
  }
  *i = s->data[s->top--];
  return 0;
}

int main(int argc, char const *argv[]) {
  int i;
  struct stack s;

  init(&s);
  push(&s, 2);
  push(&s, 4);
  push(&s, 8);
  push(&s, 16);

  pop(&s, &i);
  printf("pop() => %d\n", i);

  pop(&s, &i);
  printf("pop() => %d\n", i);

  pop(&s, &i);
  printf("pop() => %d\n", i);

  pop(&s, &i);
  printf("pop() => %d\n", i);
  return 0;
}
