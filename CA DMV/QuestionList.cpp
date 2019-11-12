//
//  QuestionList.cpp
//  CA DMV
//
//  Created by Jake Day on 11/10/19.
//  Copyright © 2019 Jake Day. All rights reserved.
//

#include "QuestionList.hpp"
#include <iostream>

using std::cout;
using std::endl;

// Load JSON upon object creation
QuestionList::QuestionList() {

}

// Load JSON file to object
void QuestionList::load() {
    cout << "Loading QuestionList from file..." << endl;
    ifstream is(QUESTION_FILE);
    // Only load if file exists
    if (is.good()) {
        JSONInputArchive iarchive(is);
        iarchive(*this);
    }
}

// Archive to JSON file
void QuestionList::save() {
    cout << "Saving QuestionList to file..." << endl;
    ofstream os(QUESTION_FILE);
    JSONOutputArchive oarchive(os);
    oarchive(*this);
}

void QuestionList::add_questions_from_file(const string &file) {
    
}

// Shift element to delete to the back, then pop
void QuestionList::remove_question(unsigned int index) {
    _question_list[index-1] = _question_list.back();
    _question_list.pop_back();
}

// Because C++ doesn't allow default arguments in overloaded operators
void QuestionList::print_questions_only() {
    for (size_type i = 0; i != this->questions().size(); i++) {
        cout << (i+1) << ". " << this->questions()[i].question() << endl;
    }
}

// Print question and answers without correct answer, for tests
void QuestionList::print_test_questions() {

}

ostream& operator<<(ostream& out, const QuestionList& q_lst) {
    for (size_type i = 0; i != q_lst.questions().size(); i++) {
        out << (i+1) << ". " << q_lst.questions()[i] << endl;
    }
    /*
    for (auto const &q : q_lst.questions()) {
        out << q << endl;
    }
        */
    return out;
}
