all: 
	moc clique.hh -o moc_clique.cc
	moc cliquetarget.hh -o moc_cliquetarget.cc
	moc dactylographie.hh -o moc_dactylographie.cc
	moc engine.hh -o moc_engine.cc
	moc mainwindow.hh -o moc_mainwindow.cc
	moc menu.hh -o moc_menu.cc
	moc target.hh -o moc_target.cc
	g++ -Wall -std=c++14 -fPIC $(shell pkg-config --cflags Qt5Widgets) *.cc -o decathlon $(shell pkg-config --libs Qt5Widgets)