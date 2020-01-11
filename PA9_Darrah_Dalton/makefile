#driver executable is made
all: testQ.o queueA.o queueN.o stackA.o
	g++ testQ.o queueA.o queueN.o stackA.o -o main

testQ.o: testQ.cpp
	g++ -c testQ.cpp -o testQ.o

queueA.o: queueA.cpp
	g++ -c queueA.cpp -o queueA.o

queueN.o: queueN.cpp
	g++ -c queueN.cpp -o queueN.o

stackA.o: stackA.cpp
	g++ -c stackA.cpp -o stackA.o

stackN.o: stackN.cpp
	g++ -c stackN.cpp -o stackN.o 
