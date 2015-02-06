CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp EvolutionaryAlgorithm.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=evolAlg

all:	$(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE):	$(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@