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

Individual::Individual(int numVariables, vector<Clause> clauses) {
    
    for (int i = 0; i < numVariables; i++){
        int randomGene = rand() % 2;
        if (randomGene == 0){
            sequence.push_back(false);
        }
        else {
            sequence.push_back(true);
        }
    }

    fitness = calcFitness(clauses);
}

/**
 *Alternate constructor to build an Individual (used when the sequence is known)
 */

Individual::Individual(vector<bool> newSequence, vector<Clause> clauses){
    sequence = newSequence;
    fitness = calcFitness(clauses);
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

double Individual::calcFitness(vector<Clause> clauses) {
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
    return (double)clausesSatisfied/clauses.size()*100;
}

/**
 *This method breeds two individuals together. It performs the crossover method,
 *given by a command line argument, with a certain probability. If crossover occurs,
 *a new sequence is generated. Otherwise, the child sequence remains the same as the
 *first individual (the one calling the method). Then, mutate is called, which has
 *a chance of mutating each gene of a certain probability. A new individual is then
 *created and returned.
 */

Individual* Individual::breed(Individual indiv, string cross, double crossProb, double mutProb, vector<Clause> clauses){
    vector<bool> newSequence;
    
    double crossoverProb = (double)rand()/RAND_MAX;
    if (crossProb > crossoverProb){
        newSequence = crossover(indiv.getSequence(), cross);
    }
    else {
        newSequence = sequence;
    }
    
    newSequence = mutate(newSequence, mutProb);

    return new Individual(newSequence, clauses);
}

/**
 *This method strictly performs the crossover portion of breeding. It creates
 *one new genetic sequence, either by crossing on a single point or by randomly
 *selecting genes from each parent sequence.
 */

vector<bool> Individual::crossover(vector<bool> secondSequence, string method){
    vector<bool> newSequence;
    if (method == "1c"){
        int index = rand() % sequence.size();
        newSequence.insert(newSequence.end(), sequence.begin(), sequence.begin()+index);
        newSequence.insert(newSequence.end(), secondSequence.begin()+index, secondSequence.end());
    }
    else {
        int count = 0;
        while (newSequence.size() != sequence.size()){
            int randomBit = rand() % 2;
            if (randomBit == 0){
                newSequence.push_back(sequence[count]);
                count++;
            }
            else {
                newSequence.push_back(secondSequence[count]);
                count++;
            }
        }
    }
    return newSequence;
}

/**
 *This method strictly performs the mutation portion of the breeding. With some
 *probability, the gene in the child sequence will be flipped (ex. true to false).
 */

vector<bool> Individual::mutate(vector<bool> newSequence, double mutProb){
    for (int i = 0; i < newSequence.size(); i++){
        double randomProb = (double)rand()/RAND_MAX;
        if (mutProb > randomProb){
            if (newSequence[i] == true){
                newSequence[i] = false;
            }
            else {
                newSequence[i] = true;
            }
        }
    }
    return newSequence;
}

/**
 *Print the actual variable names and if they have a minus (not) preceding or not.
 */

void Individual::printVariableSequence(){
    for (int i = 0; i < sequence.size(); i++){
        if (sequence[i]){
            cout << i+1 << " ";
        }
        else {
            cout << -1*(i+1) << " ";
        }
    }
    cout << "" << endl;
}



