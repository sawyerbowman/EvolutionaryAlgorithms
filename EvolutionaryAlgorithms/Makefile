# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
CC=g++
# Hey!, I am comment number 2. I want to say that CFLAGS will be the
# options I'll pass to the compiler.
CFLAGS=-c -Wall

all:	evolAlg

evolAlg:	main.o EvolutionaryAlgorithm.o Population.o Individual.o Problem.o Clause.o
	$(CC) main.o EvolutionaryAlgorithm.o Population.o Individual.o Problem.o Clause.o -o evolAlg

main.o:	main.cpp EvolutionaryAlgorithm.h
	$(CC) $(CFLAGS) main.cpp

EvolutionaryAlgorithm.o:	EvolutionaryAlgorithm.cpp EvolutionaryAlgorithm.h Population.h Problem.h
	$(CC) $(CFLAGS) EvolutionaryAlgorithm.cpp

Population.o:	Population.cpp Population.h Individual.h
	$(CC) $(CFLAGS) Population.cpp

Individual.o:	Individual.cpp Individual.h
	$(CC) $(CFLAGS) Individual.cpp

Problem.o:	Problem.cpp Problem.h Clause.h
	$(CC) $(CFLAGS) Problem.cpp

Clause.o:	Clause.cpp Clause.h
	$(CC) $(CFLAGS) Clause.cpp

clean:
	rm *o evolAlg