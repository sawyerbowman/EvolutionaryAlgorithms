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
 *Constructor initializing a EvolutionaryAlgorithm object with all the parameters set.
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
}
