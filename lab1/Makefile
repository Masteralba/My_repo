all: game

game: main.o field.o ship.o shipmanager.o
	g++ -g main.o field.o ship.o shipmanager.o -o game

main.o: main.cpp
	g++ -c -g main.cpp -o main.o

shipmanager.o: shipmanager.cpp shipmanager.hpp
	g++ -c -g shipmanager.cpp -o shipmanager.o

field.o: field.cpp field.hpp
	g++ -c -g field.cpp -o field.o

ship.o: ship.cpp ship.hpp
	g++ -c -g ship.cpp -o ship.o

make clean:
	rm *.o game