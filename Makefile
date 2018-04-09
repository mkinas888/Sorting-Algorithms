#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -pedantic -std=c++0x

__start__: sorting_algorithms
	./sorting_algorithms

sorting_algorithms: obj obj/main.o obj/AlgorithmsImplementation.o
	g++ -Wall -pedantic -std=c++0x -o sorting_algorithms obj/main.o obj/AlgorithmsImplementation.o

obj:
	mkdir obj

obj/AlgorithmsImplementation.o: AlgorithmsImplementation.cpp
	g++ -c ${CXXFLAGS} -o obj/AlgorithmsImplementation.o AlgorithmsImplementation.cpp

obj/main.o: main.cpp 
	g++ -c ${CXXFLAGS} -o obj/main.o main.cpp

clean:
	rm -f obj/*.o sorting_algorithms
