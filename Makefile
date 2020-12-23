all: main.o method.o graph_am.o graph_al.o
	gcc -o cvrp *.o -Wall

method.o: method.h method.c
	gcc -c method.h method.c -Wall

graph_am.o: graph_am.h graph_am.c
	gcc -c graph_am.h graph_am.c -Wall

graph_al.o: graph_al.h graph_al.c
	gcc -c graph_al.h graph_al.c -Wall

main.o: method.h graph_am.h graph_al.h main.c
	gcc -c method.h graph_am.h graph_al.h main.c -Wall

clean: 
	rm *.o cvrp *.gch

test:
	./main < data/data.txt

test2:
	data/script.py 10 20 1 8 15 300 | ./main

test3:
	data/script.py 50 20 1 8 15 300 | ./main
