//
//  EvolutionaryAlgorithm.cpp
//  EvolutionaryAlgorithms
//
//  Created by Sawyer Bowman on 2/5/15.
//  Copyright (c) 2015 Sawyer Bowman. All rights reserved.
//

#include "EvolutionaryAlgorithm.h"

/**
 *Constructor initializing a EvolutionaryAlgorithm object with Genetic properties.
 */

EvolutionaryAlgorithm::EvolutionaryAlgorithm(string name, int pop, string select, string cross, double probCross, double probMut, int maxGen, string alg, int printInt) {
    fileName = name;
    populationSize = pop;
    selection = select;
    crossover = cross;
    probCrossover = probCross;
    probMutation = probMut;
    maxGenerations = maxGen;
    algorithm = alg;
    printInterval = printInt;
    
    problem = new Problem(fileName);
    population = new Population(populationSize, problem->getNumVariables(), problem->getClauses());
}

/**
 *Constructor initializing a EvolutionaryAlgorithm object with PBIL properties.
 */

EvolutionaryAlgorithm::EvolutionaryAlgorithm(string name, int pop, double pos, double neg, double probMut, double mutAmt, int maxGen, string alg, int printInt) {
    fileName = name;
    populationSize = pop;
    posLearnRate = pos;
    negLearnRate = neg;
    probMutation = probMut;
    mutationAmount = mutAmt;
    maxGenerations = maxGen;
    algorithm = alg;
    printInterval = printInt;
    
    problem = new Problem(fileName);
}

/**
 *The main body of the program. This is responsible for calling fitness for
 *each individual of the population, performing selection, breeding, and
 *repeating the generational cycle until the max fitness (best satisfiability)
 *is found.
 */

void EvolutionaryAlgorithm::run(){
    //TODO: think about doing this in a do while loop
    
    //A loop for testing to make sure individual fitness is set
    //for(Individual indiv : population->getIndividuals()){
        //indiv.printFitness();
    //}
    
    population->selection(selection);
    population->printBreedingPoolSize();
    cout << populationSize << endl;
    
    
    
}




