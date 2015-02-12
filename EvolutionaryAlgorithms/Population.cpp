//
//  Population.cpp
//  EvolutionaryAlgorithms
//
//  Created by Sawyer Bowman on 2/7/15.
//  Copyright (c) 2015 Sawyer Bowman. All rights reserved.
//

#include "Population.h"

/**
 *Constructor creating a new population of individuals with random
 *genetic sequence
 */

Population::Population(int numIndiv, int numVariables, vector<Clause> clauses) {
    for (int i = 0; i < numIndiv; i++){
        Individual* newIndiv = new Individual(numVariables, clauses);
        individuals.push_back(*newIndiv);
    }
}

/**
 *This method takes in the selection method passed as a command line parameter
 *and decides which selection to do.
 */

void Population::selection(string select){
    if (select == "rs"){
        rankSelect();
    }
    else if (select == "ts"){
        tournamentSelect();
    }
    else if (select == "bs"){
        boltzmannSelect();
    }
}

/**
 *This method ranks the individuals in the population and then selects
 *them for breeding with a particular probability.
 */

void Population::rankSelect(){
    //Sort the individuals by fitness
    sort(individuals.begin(), individuals.end(), sortByFitness);
    
    //Calculate sum of series for probability calculation later
    double seriesSum = (individuals.size() * (individuals.size()+1))/2;
    
    //While breeding pool not full, add new individual
    while (breedingPool.size() != individuals.size()){
        
        //Used to select a new individual
        double randomProb = (double)rand()/RAND_MAX;
        double count = 0;
        
        //Sum up the probabilities while iterating
        for (int i = 0; i < individuals.size(); i++){
            count += (i+1)/seriesSum;
            if (count > randomProb){
                breedingPool.push_back(individuals[i]);
                //restart the for loop and continue until breedingPool is full
                break;
            }
        }
    }
}

/**
 *While there are individuals remaining, this method takes M individuals
 *and places them into a tournament. Then, the k best individuals are 
 *chosen from this tournament and added to the breeding pool.
 */

void Population::tournamentSelect(){
    vector<Individual> individualPool = individuals;
    //need to draw M from vector, select k from M, place k in pool
    while (breedingPool.size() != individuals.size()){
        vector<Individual> tournamentParticipants;
        
        //Fill the tournament with candidates until M is reached, delete candidates from overall pool
        int drawCount = 0;
        while (drawCount < M){
            int randIndex = (double)rand()/RAND_MAX;
            tournamentParticipants.push_back(individuals[randIndex]);
            drawCount++;
        }
       
        //Find the best k individuals, place them in the breeding pool, delete from tournament
        int poolCount = 0;
        while (poolCount < k && breedingPool.size() != individuals.size()){
            Individual champion = *max_element(tournamentParticipants.begin(), tournamentParticipants.end(), maxByFitness);
            breedingPool.push_back(champion);
            poolCount++;
        }
    }
}

/**
 *A very similar method to rankSelect, but uses e^fitness instead of rank
 *to calculate probability of being selected.
 */

void Population::boltzmannSelect(){
    //Sort the individuals by fitness
    sort(individuals.begin(), individuals.end(), sortByFitness);
    
    //Calculate sum of series for probability calculation later
    double seriesSum;
    for (int i = 0; i < individuals.size(); i++){
        seriesSum += pow(e, individuals[i].getFitness());
    }
    
    //While breeding pool not full, add new individual
    while (breedingPool.size() != individuals.size()){
        
        //Used to select a new individual
        double randomProb = (double)rand()/RAND_MAX;
        double count = 0;
        
        //Sum up the probabilities while iterating
        for (int i = 0; i < individuals.size(); i++){
            count += pow(e,individuals[i+1].getFitness())/seriesSum;
            if (count > randomProb){
                breedingPool.push_back(individuals[i]);
                //restart the for loop and continue until breedingPool is full
                break;
            }
        }
    }
}

/**
 *This method chooses two random individuals from the breeding pool, and creates
 *new individuals to replace them in the next generation. It calls upon crossover
 *and mutation to potentially change the gene sequence of the offspring.
 */

void Population::breed(string crossover, double probCrossover, double probMutation, vector<Clause> clauses){
    vector<Individual> newGeneration;
    
    //fill up newGeneration until it reaches the set population size
    while(newGeneration.size() != individuals.size()){
        //get two random individuals
        Individual indiv1 = getRandomIndividual();
        Individual indiv2 = getRandomIndividual();
        
        //breed the 2 individuals together to create 1 child
        Individual* child = indiv1.breed(indiv2, crossover, probCrossover, probMutation, clauses);
        newGeneration.push_back(*child);
    }
    
    individuals = newGeneration;
}

/**
 *This method is responsible for getting an individual from the population
 *and returning it.
 */

Individual Population::getRandomIndividual(){
    int randomIndex = rand() % breedingPool.size();
    return breedingPool[randomIndex];
}

/**
 *This method returns the best individual in the individuals vector.
 */

Individual Population::getBestIndividual(){
    return *max_element(individuals.begin(), individuals.end(), maxByFitness);
}


