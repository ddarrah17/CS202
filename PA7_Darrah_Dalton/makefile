#driver executable is made
all: main.o Project7.o
	g++ main.o Project7.o -o proj7

main.o: main.cpp
	g++ -c main.cpp -o main.o

Project7.o: Project7.cpp
	g++ -c Project7.cpp -o Project7.o

clean:
	rm *.o PA7