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
    Individual();
    Individual(int numVariables);
    
    //TODO: implement fitness and breed functions
    //For fitness, get variables from clause, check if satisifed in proper location of string
    int calcFitness(vector<Clause> clauses);
    void setFitness(int newFit) { fitness = newFit; }
    
    void breed();
    
    void printSequence();
    void printFitness() { cout << fitness << endl; }
    
    //TODO: figure out how to make individual work with PBIL
    
private:
    //TODO: implement helper functions for breed
    void crossover();
    void mutate();
    
    //Properties of an invidual
    vector<bool> sequence;
    int fitness;
    
    
};

#endif /* defined(__EvolutionaryAlgorithms__Individual__) */
