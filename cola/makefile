p: main.o cola.o
	gcc main.o cola.o -o p -ltbb
main.o: main.cpp cola.h 
	gcc -c main.cpp
cola.o: cola.cpp cola.h
	gcc -c cola.cpp -ltbb