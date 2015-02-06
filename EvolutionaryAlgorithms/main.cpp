//
//  main.cpp
//  EvolutionaryAlgorithms
//
//  Created by Sawyer Bowman on 2/5/15.
//  Copyright (c) 2015 Sawyer Bowman. All rights reserved.
//

#include <iostream>
#include "EvolutionaryAlgorithm.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    //Initialize an empty Evolutionary Algorithm object
    
    EvolutionaryAlgorithm ea = EvolutionaryAlgorithm();
    
    //Make sure number of command line arguments is correct (print if not)
    
    if (argc != 9){
        cout << "You've entered an incorrect number of arguments to the program!" << endl;
        cout << "   file name   = the name of the file containing the problem (string)" << endl;
        cout << "   individuals = number of individuals in population (int)" << endl;
        cout << "   selection   = type of selection of breeding pool (string):" << endl;
        cout << "                     ts   = tournament selection" << endl;
        cout << "                     rs   = rank based selection" << endl;
        cout << "                     bs   = Boltzmann selection" << endl;
        cout << "    crossover    = crossover method (string):" << endl;
        cout << "                     1c   = 1-point crossover" << endl;
        cout << "                     uc   = uniform crossover" << endl;
        cout << "    pC           = crossover probability (double)" << endl;
        cout << "    pM           = mutation probability (double)" << endl;
        cout << "    generations  = max number of generations to run (int)" << endl;
        cout << "    algorithm    = type of algorithm to run (string)" << endl;
        cout << "                     g     = Genetic Algorithm" << endl;
        cout << "                     p     = Population Based Incremental Learning (PBIL)" << endl;
        cout << "    disInterval  = show best interval (int)" << endl;
        exit(1);
    }

    //If correct number of command line arguments, convert to proper type
    
    else {
        ea.setFileName(argv[0]);
        ea.setPopulationSize(stoi(argv[1]));
        if (argv[2] == TS || argv[2] == RS || argv[2] == BS){
            ea.setSelection(argv[2]);
        }
        else {
            cout << "Invalid second argument specifying selection type.  Please use:" << endl;
            cout << "   ts  = tournament selection - implies ts1" << endl;
            cout << "   rs   = rank based selection" << endl;
            cout << "   bs   = Boltzmann selection" << endl;
            exit(1);
        }
        if (argv[3] == ONE_C || argv[3] == UNIFORM){
            ea.setCrossover(argv[3]);
        }
        else {
            cout << "Invalid fourth argument specifying crossover type.  Please use:" << endl;
            cout << "   1c  = 1-point crossover" << endl;
            cout << "   uc  = uniform crossover" << endl;
            exit(1);
        }
        ea.setProbCrossover(stod(argv[4]));
        ea.setProbMutation(stod(argv[5]));
        ea.setMaxGenerations(stoi(argv[6]));
        ea.setAlgorithm(argv[7]);
        ea.setPrintInterval(stoi(argv[8]));
        
    }

    return 0;
}
