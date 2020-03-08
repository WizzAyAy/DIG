all: 
	moc window.hh -o a.cc
	moc traducteur.hh -o b.cc
	g++ -Wall -std=c++14 -fPIC $(shell pkg-config --cflags Qt5Widgets) main.cc window.cc moteur.cc traducteur.cc a.cc b.cc -o tp1 $(shell pkg-config --libs Qt5Widgets)

clean:
	rm a.cc b.cc tp1