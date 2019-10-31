//
//  Question.cpp
//  CA DMV
//
//  Created by Jake Day on 10/29/19.
//  Copyright © 2019 Jake Day. All rights reserved.
//

#include "Question.hpp"
#include <fstream>

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
    for (auto const &ans : q.answers()) {
        out << "\t" << ans << endl;
    }
    out << "correct: " << q.correct() << endl;
    return out;
}
