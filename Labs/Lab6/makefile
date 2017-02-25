all: vectors.exe linked.exe dictionary.exe clean

vectors.exe: vectors.o
	g++ -o vectors.exe vectors.o

vectors.o: vectors.cpp
	g++ -c vectors.cpp

linked.exe: driver.o singlylinked.o doublylinked.o
	g++ -o linked.exe driver.o singlylinked.o doublylinked.o

driver.o: driver.cpp doublylinked.h singlylinked.h
	g++ -c driver.cpp

singlylinked.o: singlylinked.cpp singlylinked.h
	g++ -c singlylinked.cpp

doublylinked.o: doublylinked.cpp doublylinked.h
	g++ -c doublylinked.cpp

dictionary.exe: dictionary.o singlylinked.o
	g++ -o dictionary.exe dictionary.o singlylinked.o

dictionary.o: dictionary.cpp singlylinked.h
	g++ -c dictionary.cpp

clean: 
	rm -f *.o
