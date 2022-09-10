output: main.o window.o 
	g++ -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lstdc++ window.o main.o -o pix.build
	rm *.o
main.o: main.cpp
	g++ -c _main.cpp

window.o: window.cpp window.h
	g++ -c window.cpp

clean: 
	rm *.o pix.build

run: 
	./pix.build
