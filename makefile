output: _main.o window.o 
	g++ -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lstdc++ window.o _main.o -o output

main.o: board.h _main.cpp
	g++ -c _main.cpp

window.o: window.cpp window.h
	g++ -c window.cpp

clean: 
	rm *.o output

run: 
	./output
