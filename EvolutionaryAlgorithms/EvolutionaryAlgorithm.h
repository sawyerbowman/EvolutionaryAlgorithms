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

using namespace std;

//Constants for checking parameters passed in command line arguments

#define RS "rs"
#define TS "ts"
#define BS "bs"
#define ONE_C "1c"
#define UNIFORM "uc"

class EvolutionaryAlgorithm {
public:
    EvolutionaryAlgorithm();
    EvolutionaryAlgorithm(string name, int pop, string select, string cross, double probCross, double probMut, int maxGen, string alg, int printInt);
    
    void setFileName(string name) { fileName = name; }
    void setPopulationSize(int size) { populationSize = size; }
    void setSelection(string select) { selection = select; }
    void setCrossover(string cross) {crossover = cross; }
    void setProbCrossover(double probCross) { probCrossover = probCross; }
    void setProbMutation(double probMut) { probMutation = probMut; }
    void setMaxGenerations(int maxGen) { maxGenerations = maxGen; }
    void setAlgorithm(string alg) { algorithm = alg; }
    void setPrintInterval(int printInt) { printInterval = printInt; }
    
    
private:
    string fileName;
    int populationSize;
    string selection;
    string crossover;
    double probCrossover;
    double probMutation;
    int maxGenerations;
    string algorithm;
    int printInterval;
};

#endif /* defined(__EvolutionaryAlgorithms__EvolutionaryAlgorithm__) */
