//
//  Test.cpp
//  CA DMV
//
//  Created by Jake Day on 11/11/19.
//  Copyright © 2019 Jake Day. All rights reserved.
//

#include "Test.hpp"
#include <algorithm>
#include <random>

Test::Test(const Question_List& q_lst) {
    Question_List *test_questions = new Question_List(q_lst);
    add_to_queue(test_questions);
    _total_questions = _questions.size();
    delete test_questions;
}

// Randomize questions and add to queue
void Test::add_to_queue(Question_List *q_lst) {
    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(*q_lst), std::end(*q_lst), rng);

    for (auto q : *q_lst) {
        q.randomize_answers();
        _questions.push(q);
    }
}
