
build:
	gcc main.c functii.c -o clasament -g
	
run:
	./clasament test.in test.out test.out

clear:
	rm -f clasament