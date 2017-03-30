all: baTest.exe bank.exe company.exe clean #saTest.exe bank.exe clean

baTest.exe: baTest.o basicAccount.o
	g++ -o baTest.exe baTest.o basicAccount.o

baTest.o: baTest.cpp basicAccount.h
	g++ -c baTest.cpp

basicAccount.o: basicAccount.cpp basicAccount.h
	g++ -c basicAccount.cpp

#saTest.exe: saTest.o basicAccount.o  savingsAccount.o
#	g++ -o saTest.exe saTest.o basicAccount.o savingsAccount.o

#saTest.o: saTest.cpp savingsAccount.h
#	g++ -c saTest.cpp

savingsAccount.o: savingsAccount.cpp savingsAccount.h
	g++ -c savingsAccount.cpp

bank.exe: bank.o basicAccount.o savingsAccount.o
	g++ -o bank.exe bank.o basicAccount.o savingsAccount.o

bank.o: bank.cpp savingsAccount.h
	g++ -c bank.cpp

company.exe: company.o
	g++ -o company.exe company.o

company.o: company.cpp employee.h technical.h management.h
	g++ -c company.cpp

clean: 
	rm -f *.o
