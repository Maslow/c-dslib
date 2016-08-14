c-dslib
=======
A data structure library of c.

BUILD & TEST
============
```sh
  make          # run the testing cases
  make test     # `test` is optional, run `make` directly to test the codes
  make build    # compile *test.c
  make clean    # clean `bin/*.o`
```

DOCS
====
- linked_list_t : linked list
  * ll_insert_at()
  * ll_remove_at()
  * ll_empty()
- ll_stack_t : linked-list based stack
  * lls_push()
  * lls_pop()
  * lls_top()
- ll_queue_t : linked-list based queue
  * llq_push()
  * llq_pop()
  * llq_front()
  * llq_back()
