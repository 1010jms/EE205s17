all: driver.exe clean

driver.exe: driver.o stats.o prettyprint.o
	g++ -o driver.exe driver.o stats.o prettyprint.o

driver.o: driver.cpp stats.h prettyprint.h
	g++ -c driver.cpp

stats.o: stats.cpp stats.h
	g++ -c stats.cpp

prettyprint.o: prettyprint.cpp prettyprint.h
	g++ -c prettyprint.cpp

clean:
	rm -f *.o
