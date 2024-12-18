all: game

game: main.o field.o ship.o shipmanager.o abilities.o abilitiesmanager.o myexception.o game.o gamestate.o fileprocessor.o gamemanager.o parser.o input.o render.o display.o
	g++ -g main.o field.o ship.o shipmanager.o abilities.o abilitiesmanager.o myexception.o game.o gamestate.o fileprocessor.o gamemanager.o parser.o input.o render.o display.o -o game

main.o: main.cpp
	g++ -c -g main.cpp -o main.o

shipmanager.o: shipmanager.cpp shipmanager.hpp
	g++ -c -g shipmanager.cpp -o shipmanager.o

field.o: field.cpp field.hpp 
	g++ -c -g field.cpp -o field.o

ship.o: ship.cpp ship.hpp
	g++ -c -g ship.cpp -o ship.o

abilities.o: abilities.cpp abilities.hpp
	g++ -c -g abilities.cpp -o abilities.o

abilitiesmanager.o: abilitiesmanager.cpp abilitiesmanager.hpp 
	g++ -c -g abilitiesmanager.cpp -o abilitiesmanager.o

myexception.o: myexception.cpp myexception.hpp
	g++ -c -g myexception.cpp -o myexception.o

game.o: game.cpp game.hpp
	g++ -c -g game.cpp -o game.o

gamestate.o: gamestate.cpp gamestate.hpp
	g++ -c -g gamestate.cpp -o gamestate.o

fileprocessor.o: fileprocessor.cpp fileprocessor.hpp
	g++ -c -g fileprocessor.cpp -o fileprocessor.o

gamemanager.o: gamemanager.cpp gamemanager.hpp
	g++ -c -g gamemanager.cpp -o gamemanager.o

parser.o: parser.cpp parser.hpp
	g++ -c -g parser.cpp -o parser.o

input.o: input.cpp input.hpp
	g++ -c -g input.cpp -o input.o

render.o: render.cpp render.hpp
	g++ -c -g render.cpp -o render.o

display.o: display.cpp display.hpp
	g++ -c -g display.cpp -o display.o

make clean:
	rm *.o game