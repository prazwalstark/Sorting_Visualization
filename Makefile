CC=g++
CFLAGS=-c -w
INCLUDE_PATHS =-Iinclude
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
OBJECTS=src/*.cpp
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) $(INCLUDE_PATHS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)
