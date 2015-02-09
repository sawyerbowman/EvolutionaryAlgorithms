//
//  Problem.h
//  EvolutionaryAlgorithms
//
//  Created by Sawyer Bowman on 2/7/15.
//  Copyright (c) 2015 Sawyer Bowman. All rights reserved.
//

#ifndef __EvolutionaryAlgorithms__Problem__
#define __EvolutionaryAlgorithms__Problem__

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Clause.h"

using namespace std;

class Problem {
public:
    Problem(string fileName);
    
private:
    void parseFirstLine(string line);
    void parseClauseLine(string line);
    
    
    string problemType;
    string problemForm;
    int numVariables;
    int numClauses;
    
    //TODO: Initialize vector of Clauses
    //Clause* clauses;
    vector<Clause*> clauses;
    
};



#endif /* defined(__EvolutionaryAlgorithms__Problem__) */