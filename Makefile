CC=g++
CFLAGS=-c -std=c++11 -fPIC `root-config --cflags`
LDFLAGS=`root-config --libs`
SOURCES=UniformRandom.cc Board.cc Square.cc Piece.cc Engine2048.cc main.cc
OBJECTS=$(SOURCES:.cc=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

.cc.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJECTS) $(EXECUTABLE)
