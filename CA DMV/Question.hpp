//
//  Question.hpp
//  CA DMV
//
//  Created by Jake Day on 10/29/19.
//  Copyright © 2019 Jake Day. All rights reserved.
//

#ifndef Question_hpp
#define Question_hpp

#include <iostream>
#include <vector>
#include <string>
#include <ostream>
#include <cereal/archives/json.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/string.hpp>
#include <fstream>

using std::vector;
using std::string;
using std::ostream;

typedef vector<string> Answers;

class Question {
    string _question, _correct;
    Answers _answers;
public:
    Question();
    Question(string question, string correct);
    Question(string question, string correct, Answers answers);

    //Question& operator=(const Question& other);
    string question() const { return this->_question; }
    string correct() const { return this->_correct; }
    Answers answers() const { return this->_answers; }
    
    template<class Archive>
    void serialize(Archive& archive) { archive(_question, _correct, _answers); }
};

void write(Question *q);
void read(Question *q);
ostream& operator<<(ostream& out, const Question& q);

#endif /* Question_hpp */
