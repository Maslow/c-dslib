
#include <stdlib.h>
#include <string.h>
void *new_double(double d) {
  double *p = (double *)malloc(sizeof(double));
  *p = d;
  return (void *)p;
}

void *new_char(char c) {
  char *p = (char *)malloc(sizeof(c));
  *p = c;
  return (void *)p;
}

void *new_string(const char *s) {
  size_t len = strlen(s);
  char *p = (char *)malloc(sizeof(len + 1));
  strcpy(p, s);
  return (void *)p;
}

void *new_int(int i) {
  int *p = (int *)malloc(sizeof(int));
  *p = i;
  return (void *)p;
}

void *new_float(float f) {
  float *p = (float *)malloc(sizeof(float));
  *p = f;
  return (void *)p;
}
