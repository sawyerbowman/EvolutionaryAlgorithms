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
    Individual best = population->getBestIndividual();
    
    //while generation < maxGenerations
    int generation = 0;
    while (generation < maxGenerations){
        population->selection(selection);
        population->breed(crossover, probCrossover, probMutation, problem->getClauses());
        best = population->getBestIndividual();
        if (generation % printInterval == 0){
            cout << "o " << best.getFitness() << endl;
        }
        if (isOptimal(best)){
            break;
        }
        generation++;
    }
}

/**
 *This method checks to see if a given solution is optimal. If it is,
 *the evolution stops, and the solution is printed out.
 */

bool EvolutionaryAlgorithm::isOptimal(Individual best){
    if (best.getFitness() == problem->getNumClauses()){
        cout << "c Best Solution = " << best.getFitness() << endl;
        //TODO: introduce timers
        cout << "c Program terminated in x seconds" << endl;
        cout << "s OPTIMUM FOUND" << endl;
        //TODO: introduce variable string
        return true;
    }
    return false;
}


