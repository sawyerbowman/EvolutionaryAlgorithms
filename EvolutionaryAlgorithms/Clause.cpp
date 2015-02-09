//
//  Clause.cpp
//  EvolutionaryAlgorithms
//
//  Created by Sawyer Bowman on 2/8/15.
//  Copyright (c) 2015 Sawyer Bowman. All rights reserved.
//

#include "Clause.h"

Clause::Clause(string line){
    string word;
    stringstream lineParser (line);
    while(lineParser >> word){
        if (word == "0"){
            break;
        }
        variables.push_back(stoi(word));
    }
}

void Clause::printClause() {
    for (int i = 0; i < variables.size(); i++){
        cout << variables[i] << " ";
    }
    cout << "" << endl;
}