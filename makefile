all: 
	g++ -Wall -std=c++14 -fPIC $(shell pkg-config --cflags Qt5Widgets) main.cc window.cc calc.cpp -o tp2 $(shell pkg-config --libs Qt5Widgets)
	./tp2

clean:
	rm a.cc tp2