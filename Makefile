# CC=g++
# CFLAGS=-c -w
# LIBRARY =-Ilib
# INCLUDE_PATHS =-Iinclude
# LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
# OBJECTS=src/main.cpp
# EXECUTABLE=main.exe

# all: $(SOURCES) $(EXECUTABLE)

# $(EXECUTABLE): $(OBJECTS)
# 	$(CC) $(LDFLAGS) $(OBJECTS) $(INCLUDE_PATHS) -o $@

# .cpp.o:
# 	$(CC) $(CFLAGS) $< -o $@

all: compile link

compile:
	g++ -IC:\SFML\include -c main.cpp
link:
	g++ main.o -o main -LC:\SFML\lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
