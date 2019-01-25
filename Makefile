CC=g++
CFLAGS=-g -c -Wall -Werror -std=c++11
LDFLAGS=
SOURCES=UniformRandom.cc Board.cc Square.cc Piece.cc Engine2048.cc main.cc
OBJECTS=$(SOURCES:.cc=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cc.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJECTS) $(EXECUTABLE)
