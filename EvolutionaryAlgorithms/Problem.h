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
    
    int getNumVariables() { return numVariables; }
    int getNumClauses() { return numClauses; }
    vector<Clause> getClauses() { return clauses; }
    
private:
    void parseFirstLine(string line);
    void parseClauseLine(string line);
    
    string problemType;
    string problemForm;
    int numVariables;
    int numClauses;
    
    //Vector of clauses
    vector<Clause> clauses;
    
};



#endif /* defined(__EvolutionaryAlgorithms__Problem__) */
