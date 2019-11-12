//
//  Question.cpp
//  CA DMV
//
//  Created by Jake Day on 10/29/19.
//  Copyright © 2019 Jake Day. All rights reserved.
//

#include "Question.hpp"
#include <algorithm>
#include <random>

using std::endl;
using std::ofstream;
using std::ifstream;
using std::ios;

Question::Question()
{
}

Question::Question(string question, string correct)
    : _question(question), _correct(correct)
{
}

Question::Question(string question, string correct, Answers answers)
    : _question(question), _correct(correct), _answers(answers)
{
}

void Question::add_answer(const string& a) {
    // empty case
    if (this->_answers.empty()) {
        this->_answers['a'] = a;
        return;
    }
    unsigned char current_key, next_key;
    current_key = this->_answers.rbegin()->first;
    next_key = (unsigned char)(current_key + 1);
    this->_answers[next_key] = a;
}

// Push all keys to a vector, shuffle, then swap values in Answers map
// Adapted from: https://stackoverflow.com/questions/16068927/how-to-randomly-shuffle-values-in-a-map
void Question::randomize_answers() {
    vector<unsigned char> temp_keys;
    
    // Push keys to vector
    for (auto const& ans : this->_answers) {
        temp_keys.push_back(ans.first);
    }
    
    // Shuffle vector
    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(temp_keys), std::end(temp_keys), rng);
    
    // Swap values
    vector<unsigned char>::iterator it = temp_keys.begin();
    for (auto &ans : this->_answers) {
        string text = ans.second;
        ans.second = this->_answers[*it];
        this->_answers[*it] = text;
        it++;
    }
}

bool Question::find_by_value(const string& value, unsigned char& key) const {
    for (auto const& ans : this->_answers) {
        if (ans.second.compare(value) == 0) {
            key = ans.first;
            return true;
        }
    }
    return false;
}

void write(Question *q) {
    ofstream f;
    f.open("input.txt", ios::out);
    f.write((char*)q, sizeof(q));
}

void read(Question *q) {
    ifstream f;
    f.open("input.txt", ios::in);
    f.read((char*)q, sizeof(q));
}

ostream& operator<<(ostream& out, const Question& q) {
    out << q.question() << ":" << endl;
    for (auto const& a : q.answers()) {
        out << "\t[" << a.first << "] " << a.second << endl;
    }
    /*
    for (Answers::size_type i = 0; i != q.answers().size(); i++) {
        out << "\t[" << (char)('a'+ i) << "] " << q.answers()[i] << endl;
    }
    */
    return out;
}
