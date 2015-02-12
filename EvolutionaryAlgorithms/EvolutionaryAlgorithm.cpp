//
//  EvolutionaryAlgorithm.cpp
//  EvolutionaryAlgorithms
//
//  Created by Sawyer Bowman on 2/5/15.
//  Copyright (c) 2015 Sawyer Bowman. All rights reserved.
//

#include "EvolutionaryAlgorithm.h"

/**
 *Constructor initializing a EvolutionaryAlgorithm object with Genetic properties.
 */

EvolutionaryAlgorithm::EvolutionaryAlgorithm(string name, int pop, string select, string cross, double probCross, double probMut, int maxGen, string alg, int printInt, int staleGen) {
    fileName = name;
    populationSize = pop;
    selection = select;
    crossover = cross;
    probCrossover = probCross;
    probMutation = probMut;
    maxGenerations = maxGen;
    algorithm = alg;
    printInterval = printInt;
    quitEvolve = staleGen;
    
    problem = new Problem(fileName);
    population = new Population(populationSize, problem->getNumVariables(), problem->getClauses());
}

/**
 *Constructor initializing a EvolutionaryAlgorithm object with PBIL properties.
 */

EvolutionaryAlgorithm::EvolutionaryAlgorithm(string name, int pop, double pos, double neg, double probMut, double mutAmt, int maxGen, string alg, int printInt, int staleGen) {
    fileName = name;
    populationSize = pop;
    posLearnRate = pos;
    negLearnRate = neg;
    probMutation = probMut;
    mutationAmount = mutAmt;
    maxGenerations = maxGen;
    algorithm = alg;
    printInterval = printInt;
    quitEvolve = staleGen;
    
    problem = new Problem(fileName);
    for (int i = 0; i < problem->getNumVariables(); i++){
        probabilityVector.push_back((double)rand()/RAND_MAX);
    }
    population = new Population(populationSize, problem->getNumVariables(), problem->getClauses(), probabilityVector);
}

/**
 *The main body of the program. This is responsible for calling fitness for
 *each individual of the population, performing selection, breeding, and
 *repeating the generational cycle until the max fitness (best satisfiability)
 *is found.
 */

void EvolutionaryAlgorithm::run(){
    //start the clock
    clock_t start = clock();
    
    Individual globalBest = population->getBestIndividual();
    int genSinceBest = 0;
    
    //while generation < maxGenerations
    int generation = 0;
    while (generation < maxGenerations){
        
        if (quitEvolving(genSinceBest, false, globalBest, start)){
            break;
        }
        
        //Run the Genetic Algorithm
        if (algorithm == "g"){
            population->selection(selection);
            population->breed(crossover, probCrossover, probMutation, problem->getClauses());
        }
        
        //Run the PBIL Algorithm
        else {
            Individual newBest = population->getBestIndividual();
            Individual newWorst = population->getWorstIndividual();
            updateTowardsBest(newBest);
            updateAwayFromWorst(newBest, newWorst);
            mutateProbVector();
            population->updatePopulation(populationSize, probabilityVector, problem->getClauses());
        }
        
        //Update the global best if necessary
        Individual best = population->getBestIndividual();
        if (best.getFitness() > globalBest.getFitness()){
            globalBest = best;
            genSinceBest = 0;
        }
        
        //Print out the best of the generation (with interval)
        if (generation % printInterval == 0){
            cout << "o " << best.getFitness() << endl;
        }
        if (isSolved(best, start)){
            break;
        }
        generation++;
        genSinceBest++;
    }
    quitEvolving(genSinceBest, true, globalBest, start);
}

/**
 *This method checks to see if a given solution is optimal. If it is,
 *the evolution stops, and the solution is printed out.
 */

bool EvolutionaryAlgorithm::isSolved(Individual best, clock_t start){
    if (best.getFitness() == problem->getNumClauses()){
        cout << "c Generation's best solution = " << best.getFitness() << endl;
        cout << "c Program terminated in x seconds" << endl;
        cout << "c Program terminated in " << (clock() - start)/(double)CLOCKS_PER_SEC << " seconds" << endl;
        cout << "s PROBLEM SOLVED" << endl;
        cout << "v ";
        best.printVariableSequence();
        return true;
    }
    return false;
}

/**
 *If the user specifies a number of generations run since a new best has
 *been seen to terminate, then quit the program.
 */

bool EvolutionaryAlgorithm::quitEvolving(int generationsRun, bool done, Individual globalBest, clock_t start){
    if (quitEvolve <= generationsRun || done){
        if (done){
            cout << "c Ran though all generations and didn't satisfy all clauses" << endl;
        }
        else {
            cout << "c Terminated program after " << generationsRun << " generations since best solution encountered" << endl;
        }
        cout << "c Best solution found = " << globalBest.getFitness() << endl;
        cout << "c Program terminated in " << (clock() - start)/(double)CLOCKS_PER_SEC << " seconds" << endl;
        cout << "v ";
        globalBest.printVariableSequence();
        return true;
    }
    return false;
}

/**
 *This method updates the probability vector towards the best candidate solution
 */

void EvolutionaryAlgorithm::updateTowardsBest(Individual best) {
    for (int i = 0; i < probabilityVector.size(); i++){
        probabilityVector[i] = probabilityVector[i]*(1.0-posLearnRate)+best.getSequence()[i]*posLearnRate;
    }
}

/**
 *This method updates the probability vector away from the worst candidate solution
 */

void EvolutionaryAlgorithm::updateAwayFromWorst(Individual best, Individual worst){
    for (int i = 0; i < probabilityVector.size(); i++){
        if (best.getSequence()[i] != worst.getSequence()[i]){
            probabilityVector[i] = probabilityVector[i]*(1.0-negLearnRate)+best.getSequence()[i]*negLearnRate;
        }
    }
}

/**
 *This method mutates the probability vector
 */

void EvolutionaryAlgorithm::mutateProbVector(){
    for (int i = 0; i < probabilityVector.size(); i++){
        if ((double)rand()/RAND_MAX < probMutation){
            int mutDirection;
            if (rand() % 2 == 1){
                mutDirection = 1;
            }
            else {
                mutDirection = 0;
            }
            probabilityVector[i] = probabilityVector[i]*(1.0-mutationAmount)+mutDirection*(mutationAmount);
        }
    }
}


