CC=g++
CFLAGS=-g -c -Wall -Werror
LDFLAGS=
SOURCES=UniformRandom.cc Board.cc Square.cc Piece.cc 2048Engine.cc main.cc
OBJECTS=$(SOURCES:.cc=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cc.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJECTS) $(EXECUTABLE)
