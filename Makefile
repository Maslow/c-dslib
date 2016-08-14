.PHONY:test
test:bin/*.out
	 clear
	 # #################################################
	 # TEST: linked_list.out
	 bin/linked_list.out
	 # <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	 # TEST: stack.out
	 bin/stack.out
	 # <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	 # TEST: queue.out
	 bin/queue.out
	 # <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

build:bin/*.out
	@

bin/*.out:test/*test.c
	gcc test/linked_list_test.c -o bin/linked_list.out
	gcc test/ll_stack_test.c -o bin/stack.out
	gcc test/ll_queue_test.c -o bin/queue.out

clean:
	rm -f bin/*.out
