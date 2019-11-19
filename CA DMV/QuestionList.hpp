//
//  QuestionList.hpp
//  CA DMV
//
//  Created by Jake Day on 11/10/19.
//  Copyright © 2019 Jake Day. All rights reserved.
//

#ifndef QuestionList_hpp
#define QuestionList_hpp

#include "Question.hpp"

//#define QUESTION_FILE "/Users/jakeday/questions.json"

using namespace cereal;

using std::ofstream;
using std::ifstream;

typedef vector<Question> Question_List;

class QuestionList {
    Question_List _question_list;
public:
    QuestionList();
    void load();
    void save();
    void add_question(const Question& q) { _question_list.push_back(q); }
    void add_questions_from_file(const string &file);
    void remove_question(unsigned int index);
    void remove_all_questions() { this->_question_list.clear(); }
    void print_questions_only();
    void print_test_questions();
    Question_List questions() const { return _question_list; }
    
    template<class Archive>
    void serialize(Archive& archive) { archive(_question_list); }
};


ostream& operator<<(ostream& out, const QuestionList& q_lst);

#endif /* QuestionList_hpp */
