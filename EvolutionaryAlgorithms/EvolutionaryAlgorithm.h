//
//  GenticAlgorithm.h
//  EvolutionaryAlgorithms
//
//  Created by Sawyer Bowman on 2/5/15.
//  Copyright (c) 2015 Sawyer Bowman. All rights reserved.
//

#ifndef __EvolutionaryAlgorithms__EvolutionaryAlgorithm
#define __EvolutionaryAlgorithms__EvolutionaryAlgorithm

#include <stdio.h>
#include <iostream>
#include "Population.h"
#include "Problem.h"

using namespace std;

//Constants for checking parameters passed in command line arguments
const string RS = "rs";
const string TS = "ts";
const string BS = "bs";
const string ONE_C = "1c";
const string UNIFORM = "uc";

class EvolutionaryAlgorithm {
    
public:
    //Initialize an empty EvolutionaryAlgorithm object
    EvolutionaryAlgorithm();
    
    //Initialize EvolutionaryAlgorithm object for Genetic
    EvolutionaryAlgorithm(string name, int pop, string select, string cross, double probCross, double probMut, int maxGen, string alg, int printInt);
    
    //Initialize EvolutionaryAlgorithm object for PBIL
    EvolutionaryAlgorithm(string name, int pop, double pos, double neg, double probMut, double mutAmt, int maxGen, string alg, int printInt);
    
    //The body of the algorithm goes here
    void run();
    
private:
    //Shared properties between Genetic and PBIL
    string fileName;
    int populationSize;
    double probMutation;
    int maxGenerations;
    string algorithm;
    int printInterval;
    
    //Genetic specific properties
    string selection;
    string crossover;
    double probCrossover;
    Population* population;
    
    //PBIL specific properties
    double posLearnRate;
    double negLearnRate;
    double mutationAmount;
    
    //Problem object to contain problem from file
    Problem* problem;
    
};

#endif /* defined(__EvolutionaryAlgorithms__EvolutionaryAlgorithm__) */
