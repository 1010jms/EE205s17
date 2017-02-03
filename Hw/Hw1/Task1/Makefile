all: driver.exe driver2.exe clean

driver.exe: driver.o stats.o prettyprint.o
	g++ -o driver.exe driver.o stats.o prettyprint.o

driver.o: driver.cpp stats.h prettyprint.h
	g++ -c driver.cpp

stats.o: stats.cpp stats.h
	g++ -c stats.cpp

prettyprint.o: prettyprint.cpp prettyprint.h
	g++ -c prettyprint.cpp

driver2.exe: driver2.o life.o prettyprint.o
	g++ -o driver2.exe driver2.o life.o prettyprint.o

driver2.o: driver2.cpp life.h prettyprint.h
	g++ -c driver2.cpp

life.o: life.cpp life.h
	g++ -c life.cpp

# prettyprint.o: prettyprint.cpp prettyprint.h
#	g++ -c prettyprint.cpp

clean:
	rm -f *.o
