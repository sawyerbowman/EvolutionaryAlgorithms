//
//  Population.cpp
//  EvolutionaryAlgorithms
//
//  Created by Sawyer Bowman on 2/7/15.
//  Copyright (c) 2015 Sawyer Bowman. All rights reserved.
//

#include "Population.h"

/**
 *Constructor creating a new population of individuals
 */

Population::Population(int numIndiv) {
    individuals = new Individual[numIndiv];
    for (int i = 0; i < numIndiv; i++){
        //TODO: need to think of parameters to pass into Individual... sequence and initial fitness of 0?
        Individual* newIndiv = new Individual();
        individuals[i] = *newIndiv;
    }
}