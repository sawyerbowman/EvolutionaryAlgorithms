//
//  Individual.h
//  EvolutionaryAlgorithms
//
//  Created by Sawyer Bowman on 2/7/15.
//  Copyright (c) 2015 Sawyer Bowman. All rights reserved.
//

#ifndef __EvolutionaryAlgorithms__Individual__
#define __EvolutionaryAlgorithms__Individual__

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Clause.h"

using namespace std;

class Individual {
public:
    //Constructors
    Individual(int numVariables, vector<Clause> clauses);
    Individual(vector<bool> newSequence, vector<Clause> clauses);
    
    //For fitness, get variables from clause, check if satisifed in proper location of string
    double calcFitness(vector<Clause> clauses);
    void setFitness(int newFit) { fitness = newFit; }
    void printFitness() { cout << fitness << endl; }
    double getFitness() { return fitness; }
    
    //Breed function
    Individual* breed(Individual indiv, string cross, double crossProb, double mutProb, vector<Clause> clauses);
    
    void printSequence();
    void printVariableSequence();
    
    void setRank(int newRank) { rank = newRank; }
    int getRank() { return rank; }
    
    vector<bool> getSequence() { return sequence; }
    
    //TODO: figure out how to make individual work with PBIL
    
private:
    //TODO: implement helper functions for breed
    vector<bool> crossover(vector<bool> secondSequence, string method);
    vector<bool> mutate(vector<bool>, double mutProb);
    
    //Properties of an invidual
    vector<bool> sequence;
    double fitness;
    int rank;
    
    
};

#endif /* defined(__EvolutionaryAlgorithms__Individual__) */
