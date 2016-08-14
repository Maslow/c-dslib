test:bin/*.o
	 clear
	 # #################################################
	 # TEST: linked_list.o
	 bin/linked_list.o
	 # <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	 # TEST: stack.o
	 bin/stack.o
	 # <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	 # TEST: queue.o
	 bin/queue.o
	 # <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

build:bin/*.o
	@

bin/*.o:*test.c
	gcc linked_list_test.c -o bin/linked_list.o
	gcc ll_stack_test.c -o bin/stack.o
	gcc ll_queue_test.c -o bin/queue.o

clean:
	rm -f bin/*.o
