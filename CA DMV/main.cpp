//
//  main.cpp
//  CA DMV
//
//  Created by Jake Day on 10/29/19.
//  Copyright © 2019 Jake Day. All rights reserved.
//

#include <iostream>
#include "Question.hpp"
#include "welcome.h"

#define QUESTION_FILE "questions.json"

using namespace cereal;

using std::cin;
using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;

int main(int argc, const char * argv[]) {
    welcome();
    /*
    string q = "test";
    Answers a {"a","b","c"};
    string c = "a";
    Question q1(q,c,a);
    cout << q1 << endl;
    {
        ofstream os(QUESTION_FILE);
        JSONOutputArchive oarchive(os);
        oarchive(q1);
    }
    Question q2;
    {
        ifstream is(QUESTION_FILE);
        JSONInputArchive iarchive(is);
        iarchive(q2);
        
    }
    cout << q2 << endl;
     */
    
    
    
    return 0;
}
