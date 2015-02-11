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
    double seriesSum = (individuals.size() * individuals.size()-1)/2;
    
    //Loop through the sorted list, assigning ranks and determining breeding pool
    for (int i = 0; i < individuals.size(); i++){
        individuals[i].setRank(i+1);
        double indivProbability = (individuals[i].getRank()/seriesSum);
        double actualProbability = (double)rand()/RAND_MAX;
        if (indivProbability > actualProbability){
            breedingPool.push_back(individuals[i]);
        }
    }
}

/**
 *While there are individuals remaining, this method takes M individuals
 *and places them into a tournament and eliminates them from the main
 *population. Then, the k best individuals are chosen from this tournament
 *and added to the breeding pool.
 */

void Population::tournamentSelect(){
    vector<Individual> individualPool = individuals;
    //need to draw M from vector, delete M from vector, place k in pool
    while (!individualPool.empty()){
        vector<Individual> tournamentParticipants;
        
        //Fill the tournament with candidates until M is reached, delete candidates from overall pool
        int drawCount = 0;
        while (drawCount < M && individualPool.size() > 0){
            int random = rand() % individualPool.size();
            tournamentParticipants.push_back(individualPool[random]);
            individualPool.erase(individualPool.begin()+random);
            drawCount++;
        }
       
        //Find the best k individuals, place them in the breeding pool, delete from tournament
        int poolCount = 0;
        while (poolCount < k && tournamentParticipants.size() > 0){
            //was thinking about using *max_element, but sort works best for now
            sort(tournamentParticipants.begin(), tournamentParticipants.end(), sortByFitness);
            breedingPool.push_back(tournamentParticipants.back());
            tournamentParticipants.erase(tournamentParticipants.end()-1);
            poolCount++;
        }
    }
}

/**
 *
 */

void Population::boltzmannSelect(){
    
}

/**
 *This method chooses two random individuals from the breeding pool, and creates
 *two new individuals to replace them in the next generation. It calls upon crossover
 *and mutation to potentially change the gene sequence of the offspring.
 */

void Population::breed(string crossover, double probCrossover, double probMutation, vector<Clause> clauses){
    vector<Individual> newGeneration;
    
    //TODO: what is population size is odd?
    while(!individuals.empty()){
        Individual indiv1 = getRandomIndividualAndErase();
        Individual indiv2 = getRandomIndividualAndErase();

        Individual* child1 = indiv1.breed(indiv2, crossover, probCrossover, probMutation, clauses);
        newGeneration.push_back(*child1);
        
        Individual* child2 = indiv2.breed(indiv1, crossover, probCrossover, probMutation, clauses);
        newGeneration.push_back(*child2);
    }
    
    individuals = newGeneration;
}

/**
 *This method is responsible for getting an individual from the population
 *storing it, erasing it from the vector, and returning it.
 */

Individual Population::getRandomIndividualAndErase(){
    int randomIndex = rand() % individuals.size();
    Individual indiv = individuals[randomIndex];
    individuals.erase(individuals.begin() + randomIndex);
    return indiv;
}

/**
 *This method returns the best individual in the individuals vector.
 */

Individual Population::getBestIndividual(){
    return *max_element(individuals.begin(), individuals.end(), maxByFitness);
}


