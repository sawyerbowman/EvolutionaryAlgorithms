# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
CC=g++
# Hey!, I am comment number 2. I want to say that CFLAGS will be the
# options I'll pass to the compiler.
CFLAGS=-c -Wall

all:	evolAlg

evolAlg:	main.o EvolutionaryAlgorithm.o
	$(CC) main.o EvolutionaryAlgorithm.o -o evolAlg

main.o:	main.cpp EvolutionaryAlgorithm.h
	$(CC) $(CFLAGS) main.cpp

EvolutionaryAlgorithm.o:	EvolutionaryAlgorithm.cpp EvolutionaryAlgorithm.h
	$(CC) $(CFLAGS) EvolutionaryAlgorithm.cpp

clean:
	rm *o evolAlg