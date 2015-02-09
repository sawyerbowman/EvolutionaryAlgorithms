//
//  Problem.cpp
//  EvolutionaryAlgorithms
//
//  Created by Sawyer Bowman on 2/7/15.
//  Copyright (c) 2015 Sawyer Bowman. All rights reserved.
//

#include "Problem.h"

/**
 *The problem constructor takes in a file name and reads in each line.
 *If the line is a comment, it is skipped. The first line stores the
 *correct properties. Clause lines are parsed and then stored.
 */

Problem::Problem(string fileName){
    //Try to read in the file
    ifstream problemFile(fileName);
    
    //String to hold each line
    string line;
    
    //If file is valid, continue parsing
    if (problemFile.is_open()){
        while (getline(problemFile, line)){
            if (line[0] == 'c'){
                //the line is a comment, skip forward
                continue;
            }
            else if (line[0] == 'p'){
                //parse first line (problem, cnf, #variables, #clauses)
                parseFirstLine(line);
            }
            else {
                //parse each line into a clause object, save into array of clauses
                Clause* newClause = new Clause(line);
                //newClause->printClause();
                clauses.push_back(*newClause);
            }
        }
        problemFile.close();
    }
    
    //If file invalid, print out error message and quit
    else {
        cout << "Please enter a valid file name. This name could not open a file." << endl;
        exit(1);
    }
    
}

/**
 *Takes the first line and assigns the appropriate parts of the line
 *to the correct variable.
 */

void Problem::parseFirstLine(string line){
    string word;
    stringstream lineParser (line);
    int count = 1;
    while(lineParser >> word) {
        switch (count) {
            case 1:
                problemType = word;
                count++;
                break;
                
            case 2:
                problemForm = word;
                count++;
                break;
                
            case 3:
                numVariables = stoi(word);
                count++;
                break;
                
            case 4:
                numClauses = stoi(word);
                count++;
                break;
                
            default:
                break;
        }
    }
}

