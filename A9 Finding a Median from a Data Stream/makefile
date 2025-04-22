median: main.o
	g++ main.cpp Heap.cpp -o median.exe

main.o: main.cpp Heap.h Heap.cpp
	g++ -c main.cpp

clean:
	del *.o *.exe