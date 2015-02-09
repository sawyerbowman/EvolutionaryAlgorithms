//
//  Population.cpp
//  EvolutionaryAlgorithms
//
//  Created by Sawyer Bowman on 2/7/15.
//  Copyright (c) 2015 Sawyer Bowman. All rights reserved.
//

#include "Population.h"

/**
 *Constructor creating a new population of individuals with random
 *genetic sequence
 */

Population::Population(int numIndiv, int numVariables) {
    for (int i = 0; i < numIndiv; i++){
        Individual* newIndiv = new Individual(numVariables);
        //newIndiv->printSequence();
        individuals.push_back(*newIndiv);
    }
}