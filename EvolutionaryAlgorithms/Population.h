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
#include "Individual.h"

using namespace std;

class Population {
public:
    Population();
    Population(int numIndiv);
    //TODO: implement selection method
    void selection(string select);
    
    //TODO: implement methods to make population work with PBIL
    
private:
    //TODO: implement helper methods for selection
    void tournamentSelect();
    void rankSelect();
    void boltzmannSelect();
    
    //Array of Individuals representing a population
    Individual* individuals;
    
};


#endif /* defined(__EvolutionaryAlgorithms__Population__) */
