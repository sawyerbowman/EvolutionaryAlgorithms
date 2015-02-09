//
//  Individual.cpp
//  EvolutionaryAlgorithms
//
//  Created by Sawyer Bowman on 2/7/15.
//  Copyright (c) 2015 Sawyer Bowman. All rights reserved.
//

#include "Individual.h"

/**
 *Constructor creating a single individual with a random gene sequence.
 *The individual is the same length as the number of variables in the problem.
 *Each index+1 corresponds to a variable.
 */

Individual::Individual(int numVariables) {
    
    for (int i = 0; i < numVariables; i++){
        int randomGene = rand() % 2;
        if (randomGene == 0){
            sequence.push_back(false);
        }
        else {
            sequence.push_back(true);
        }
    }
    
    //Assume fitness of 0 until we set it later
    fitness = 0;
}

/**
 *This method simply prints out the genetic sequence per individual (1 and 0)
 */

void Individual::printSequence() {
    for (bool gene : sequence){
        cout << gene;
    }
    cout << "" << endl;
}

/**
 *This function takes in the vector of clauses from the problem. For every clause
 *it finds the appropriate variables in the genetic sequence and evaluates whether
 *the gene satisfies the clause.
 */

int Individual::calcFitness(vector<Clause> clauses) {
    int clausesSatisfied = 0;
    for (Clause clause : clauses){
        for (int variable : clause.getVariables()){
            int index = abs(variable) - 1;
            //If variable and true in sequence
            if (variable > 0 && sequence[index]){
                clausesSatisfied++;
                break;
            }
            //If not variable and false in sequence
            else if (variable < 0 && !sequence[index]){
                clausesSatisfied++;
                break;
            }
        }
    }
    return clausesSatisfied;
}
