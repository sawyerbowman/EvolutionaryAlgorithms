//
//  EvolutionaryAlgorithm.cpp
//  EvolutionaryAlgorithms
//
//  Created by Sawyer Bowman on 2/5/15.
//  Copyright (c) 2015 Sawyer Bowman. All rights reserved.
//

#include "EvolutionaryAlgorithm.h"

/**
 *Constructor initializing an empty EvolutionaryAlgorithm object.
 */

EvolutionaryAlgorithm::EvolutionaryAlgorithm(){
    fileName = "";
    populationSize = 0;
    selection = "";
    crossover = "";
    probCrossover = 0;
    probMutation = 0;
    maxGenerations = 0;
    algorithm = "";
    printInterval = 0;
}

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
    
    population = new Population(populationSize);
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
}
