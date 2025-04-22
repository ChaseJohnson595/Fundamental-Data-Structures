median: main.o
	g++ main.cpp Heap.cpp MaxHeap.cpp -o median.exe

main.o: main.cpp Heap.h MaxHeap.h MaxHeap.cpp Heap.cpp
	g++ -c main.cpp

clean:
	del *.o *.exe