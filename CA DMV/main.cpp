//
//  main.cpp
//  CA DMV
//
//  Created by Jake Day on 10/29/19.
//  Copyright © 2019 Jake Day. All rights reserved.
//

#include <iostream>
#include "QuestionList.h"
#include "welcome.h"

#define QUESTION_FILE "/Users/jakeday/questions.json"

using namespace cereal;

using std::cin;
using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;

int main(int argc, const char * argv[]) {
    welcome();
    
    string q = "test";
    Answers a {"a","b","c"};
    string c = "a";
    Question q1(q,c,a);
    cout << q1 << endl;

    Question q2(q,c,a);
    
    QuestionList q_lst;
    q_lst.add_question(q1);
    q_lst.add_question(q2);
    
    {
        ofstream os(QUESTION_FILE);
        JSONOutputArchive oarchive(os);
        oarchive(q_lst);
    }
    
    {
        QuestionList q_lst_2;
        ifstream is(QUESTION_FILE);
        JSONInputArchive iarchive(is);
        iarchive(q_lst_2);
        cout << q_lst_2 << endl;
    }

    
    return 0;
}
