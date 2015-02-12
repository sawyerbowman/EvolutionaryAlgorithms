//
//  Population.h
//  EvolutionaryAlgorithms
//
//  Created by Sawyer Bowman on 2/7/15.
//  Copyright (c) 2015 Sawyer Bowman. All rights reserved.
//

#ifndef __EvolutionaryAlgorithms__Population__
#define __EvolutionaryAlgorithms__Population__

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "Individual.h"
#include "Clause.h"

using namespace std;

const int M = 2;
const int k = 1;
const double e = exp(1.0);

//Sorts ascending by fitness (lowest to highest)
static bool sortByFitness(Individual firstIndiv, Individual secondIndiv) { return firstIndiv.getFitness() < secondIndiv.getFitness(); }
static bool maxByFitness(Individual firstIndiv, Individual secondIndiv) { return firstIndiv.getFitness() < secondIndiv.getFitness(); }

class Population {
public:
    Population();
    Population(int numIndiv, int numVariables, vector<Clause> clauses);

    void selection(string select);
    
    void breed(string crossover, double probCrossover, double probMutation, vector<Clause> clauses);
    
    vector<Individual> getIndividuals() { return individuals; }
    vector<Individual> getBreedingPool() { return breedingPool; }
    Individual getBestIndividual();
    
    void printBreedingPoolSize() { cout << breedingPool.size() << endl; }
    
    //TODO: implement methods to make population work with PBIL
    
private:
    //helper functions for select()
    void tournamentSelect();
    void rankSelect();
    void boltzmannSelect();
    
    Individual getRandomIndividual();
    
    //Vector of Individuals representing a population
    vector<Individual> individuals;
    
    //Vector of Individuals selected via a selection method for the breeding pool
    vector<Individual> breedingPool;
    
};

#endif /* defined(__EvolutionaryAlgorithms__Population__) */
