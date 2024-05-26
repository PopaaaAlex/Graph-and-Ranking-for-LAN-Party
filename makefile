
build:
	gcc main.c ./Functii/functii.c ./Functii/coada.c -o clasament -g
	
run:
	./clasament test.in test.out test.out

clear:
	rm -f clasament