LIBS=-lm
CC=gcc -g -Wall -Wextra -std=gnu99

b_tree: test_b_tree.o b_tree.o
	$(CC) test_b_tree.o b_tree.o -o b_tree $(LIBS)

test_b_tree.o: test_b_tree.c
	$(CC) test_b_tree.c -c $(LIBS)

b_tree.o: b_tree.c b_tree.h
	$(CC) b_tree.c -c $(LIBS)

run: b_tree
	./b_tree

clean:
	rm -rf *.o b_tree; clear