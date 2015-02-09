//
//  Clause.h
//  EvolutionaryAlgorithms
//
//  Created by Sawyer Bowman on 2/8/15.
//  Copyright (c) 2015 Sawyer Bowman. All rights reserved.
//

#ifndef __EvolutionaryAlgorithms__Clause__
#define __EvolutionaryAlgorithms__Clause__

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class Clause {
public:
    Clause(string line);
    
    vector<int> getVariables() { return variables; }
    
    void printClause();
    
private:
    //Use a vector here because dynamic and don't num variables in line
    vector<int> variables;
    
};

#endif /* defined(__EvolutionaryAlgorithms__Clause__) */
