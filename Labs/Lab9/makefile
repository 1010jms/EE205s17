all: main.exe clean

main.exe: main.o stack-array.o stack-list.o singlylinked.o
	g++ -o main.exe main.o stack-array.o stack-list.o singlylinked.o

main.o: main.cpp stack.h
	g++ -c main.cpp singlylinked.cpp

stack-array.o: stack-array.cpp stack.h
	g++ -c stack-array.cpp

stack-list.o: stack-list.cpp stack.h
	g++ -c stack-list.cpp

singlylinked.o: singlylinked.cpp singlylinked.h
	g++ -c singlylinked.cpp

clean:
	rm -f *.o
