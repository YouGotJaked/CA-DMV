//
//  QuestionList.h
//  CA DMV
//
//  Created by Jake Day on 10/31/19.
//  Copyright © 2019 Jake Day. All rights reserved.
//

#ifndef QuestionList_h
#define QuestionList_h

#define QUESTION_FILE "/Users/jakeday/questions.json"

#include "Question.hpp"

using namespace cereal;

using std::ofstream;
using std::ifstream;

typedef vector<Question> Question_List;

class QuestionList {
    Question_List _question_list;
public:
    QuestionList();
    void add_question(const Question& q) { _question_list.push_back(q); }
    void save();
    Question_List questions() const { return _question_list; }
    
    template<class Archive>
    void serialize(Archive& archive) { archive(_question_list); }
};

// Load JSON upon object creation
inline QuestionList::QuestionList() {
    ifstream is(QUESTION_FILE);
    JSONInputArchive iarchive(is);
    iarchive(*this);
}

// Archive to JSON file
inline void QuestionList::save() {
    ofstream os(QUESTION_FILE);
    JSONOutputArchive oarchive(os);
    oarchive(*this);
}

inline ostream& operator<<(ostream& out, const QuestionList& q_lst) {
    for (auto const &q : q_lst.questions()) {
        out << q << std::endl;
    }
    return out;
}

#endif /* QuestionList_h */
