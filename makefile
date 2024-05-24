
build:
	gcc main.c -o clasament -g
	
run:
	./clasament test.in test.out test.out

clear:
	rm -f clasament