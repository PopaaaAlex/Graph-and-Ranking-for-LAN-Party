
build:
	gcc main.c ./Functii/functii.c ./Functii/coada_graph.c -o clasament -g
	
run:
	./clasament test.in test.out test.out
