all: main clean

main: main.o universal_heap.o
	g++ main.o universal_heap.o -o main

main.o: main.cpp universal_heap.h
	g++ -c main.cpp

universal_heal.o: universal_heap.cpp universal_heap.h
	g++ -c universal_heap.cpp

clean:
	rm -rf *.o