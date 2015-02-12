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
#include <cstdio>
#include <ctime>

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
    EvolutionaryAlgorithm(string name, int pop, string select, string cross, double probCross, double probMut, int maxGen, string alg, int printInt, int staleGen);
    
    //Initialize EvolutionaryAlgorithm object for PBIL
    EvolutionaryAlgorithm(string name, int pop, double pos, double neg, double probMut, double mutAmt, int maxGen, string alg, int printInt, int staleGen);
    
    //The body of the algorithm goes here
    void run();
    
private:
    bool isSolved(Individual best, clock_t start);
    bool quitEvolving(int generationsRun, bool done, Individual globalBest, clock_t start);
    
    //Updates to Probability Vector
    void updateTowardsBest(Individual best);
    void updateAwayFromWorst(Individual best, Individual worst);
    void mutateProbVector();
    
    //Shared properties between Genetic and PBIL
    string fileName;
    int populationSize;
    double probMutation;
    int maxGenerations;
    string algorithm;
    int printInterval;
    int quitEvolve;
    Population* population;
    
    //Genetic specific properties
    string selection;
    string crossover;
    double probCrossover;
    
    //PBIL specific properties
    double posLearnRate;
    double negLearnRate;
    double mutationAmount;
    vector<double> probabilityVector;
    
    //Problem object to contain problem from file
    Problem* problem;
    
};

#endif /* defined(__EvolutionaryAlgorithms__EvolutionaryAlgorithm__) */
