#driver executable is made
all: main.o Agency.o
	g++ main.o Agency.o -o proj6

main.o: main.cpp
	g++ -c main.cpp -o main.o

Agency.o: Agency.cpp
	g++ -c Agency.cpp -o Agency.o

clean:
	rm *.o PA6