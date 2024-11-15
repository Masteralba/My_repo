all: game

game: main.o field.o ship.o shipmanager.o abilities.o abilitiesmanager.o
	g++ -g main.o field.o ship.o shipmanager.o abilities.o abilitiesmanager.o -o game

main.o: main.cpp
	g++ -c -g main.cpp -o main.o

shipmanager.o: shipmanager.cpp shipmanager.hpp
	g++ -c -g shipmanager.cpp -o shipmanager.o

field.o: field.cpp field.hpp myexception.hpp
	g++ -c -g field.cpp -o field.o

ship.o: ship.cpp ship.hpp
	g++ -c -g ship.cpp -o ship.o

abilities.o: abilities.cpp abilities.hpp
	g++ -c -g abilities.cpp -o abilities.o

abilitiesmanager.o: abilitiesmanager.cpp abilitiesmanager.hpp myexception.hpp
	g++ -c -g abilitiesmanager.cpp -o abilitiesmanager.o


make clean:
	rm *.o game