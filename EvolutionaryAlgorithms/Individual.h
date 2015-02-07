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

using namespace std;

class Individual {
public:
    //TODO: think about proper parameters for this method
    Individual();
    //TODO: implement fitness and breed functions
    void calcFitness();
    void breed();
    
    //TODO: figure out how to make individual work with PBIL
    
private:
    //TODO: implement helper functions for breed
    void crossover();
    void mutate();
    
    //Properties of an invidual
    string sequence;
    double fitness;
    
    
};

#endif /* defined(__EvolutionaryAlgorithms__Individual__) */
