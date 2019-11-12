//
//  Test.hpp
//  CA DMV
//
//  Created by Jake Day on 11/11/19.
//  Copyright © 2019 Jake Day. All rights reserved.
//

#ifndef Test_hpp
#define Test_hpp

#include "QuestionList.hpp"
#include <queue>

using std::queue;

typedef queue<Question> QuestionQueue;

class Test {
    QuestionQueue _questions;
    unsigned long _total_questions, _total_correct = 0;
    double _percent_correct;
public:
    Test(const Question_List& q);
    
    void add_to_queue(Question_List *q_lst);
    void randomize_questions();
    void randomize_answers();
    void update_total_correct() { _total_correct += 1; }
    void update_percent_correct();
    void next_question() { _questions.pop(); }
    
    QuestionQueue questions() const { return this->_questions; }
    Question current_question() const { return this->_questions.front(); }
    unsigned long total_questions() const { return this->_total_questions; }
    unsigned long total_correct() const { return this->_total_correct; }
    double percent_correct() const { return this->_percent_correct; }
    
};

ostream& operator<<(ostream& out, const Test& t);
#endif /* Test_hpp */
