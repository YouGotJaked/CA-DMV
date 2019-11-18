//
//  welcome.cpp
//  CA DMV
//
//  Created by Jake Day on 10/30/19.
//  Copyright © 2019 Jake Day. All rights reserved.
//

#include "welcome.h"
#include "Test.hpp"
#include <string>
#include <iostream>
#include <vector>

using std::string;
using std::to_string;
using std::stringstream;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::transform;


// Adapted from: https://stackoverflow.com/questions/313970/how-to-convert-stdstring-to-lower-case
void to_lowercase(string& str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

// Adapted from: https://stackoverflow.com/questions/2840835/way-to-get-unsigned-char-into-a-stdstring-without-reinterpret-cast
string unsigned_char_to_string(const unsigned char& c) {
    stringstream ss;
    ss << c;
    return ss.str();
}

void admin_mode() {
    cout << "\nEntering admin interface..." << endl;
    Menu_Engine(ADMIN_MENU, ADMIN_MENU_SIZE);
}

// Create a Test to randomize questions and answers
void new_test() {
    string input, correct_key_str, correct_text;
    unsigned int current_q;
    unsigned char correct_key;
    Test t(Test_Questions.questions());
    
    cout << "\nStarting new test..." << endl;
    
    for (current_q = 1; !t.questions().empty(); current_q++, t.next_question()) {
        cout << current_q << ". " << t.current_question() << endl;
        cout << "Your answer:\t";
        getline(cin, input);
        
        correct_text = t.current_question().correct();
        t.current_question().find_by_value(correct_text, correct_key);
        correct_key_str = unsigned_char_to_string(correct_key);
        
        if (input.compare(correct_key_str) == 0) {
            cout << "Correct!" << endl;
            t.update_total_correct();
        } else {
            cout << "Incorrect! You answered [" << input << "] but the correct answer was [" << correct_key << "]" << endl;
        }
    }
    t.update_percent_correct();
    cout << "You got " << t.percent_correct() << "% correct!" << endl;
}

void previous_test() {
    cout << "\nDisplaying previous test results..." << endl;
}

void quit() {
    cout << "\nQuitting..." << endl;
    _Exit(0);
}

void back() {
    cout << "back back back it up" << endl;
}

void display_questions() {
    cout << Test_Questions << endl;
}

// Add elements to Test_Questions
void add_question() {
    string input, c;
    Question q;
    Answers a;
    
    cout << "Question:\t";
    getline(cin, input);
    q.set_question(input);
    
    do {
        cout << "Add an answer:\t";
        getline(cin, input);
        q.add_answer(input);
        //a.push_back(input);
        
        cout << "Correct answer? [Y/N]\t";
        getline(cin, input);
        to_lowercase(input);
 
        if (input.compare("y") == 0) {
            c = q.answers().rbegin()->second;
            //c = a.back();
        } else if (input.compare("n") != 0) {
            cout << "Interpreted input as 'N'" << endl;
        }
        
        // Correct answer must be defined
        if (!c.empty()) {
            cout << "Done? [Y/N]\t";
            getline(cin, input);
            to_lowercase(input);
     
            if (input.compare("y") == 0) {
                break;
            } else if (input.compare("n") != 0) {
                cout << "Interpreted input as 'N'" << endl;
            }
        }
    } while (true);

    q.set_correct(c);
    Test_Questions.add_question(q);
    Test_Questions.save();
}

// Remove elements at the specified indexes in Test_Questions
void remove_question() {
    string input;
    unsigned int index;
    vector<unsigned int> to_delete;
    
    cout << "Please enter the number of the question(s) you would like to remove, or type 'all' to remove all questions:" << endl;
    Test_Questions.print_questions_only();
       
    do {
        cout << "Question Number:\t";
        getline(cin, input);
        
        if (is_numeric(input)) {
            index = stoi(input, nullptr);
            if (index <= 0 || index > Test_Questions.questions().size()) {
                cout << "Index does not exist." << endl;
            } else {
                to_delete.push_back(index);
            }
        } else {
            to_lowercase(input);
            if (input.compare("all") == 0) {
                Test_Questions.remove_all_questions();
            }
            cout << "Input must be numeric." << endl;
        }
    
        cout << "Done? [Y/N]\t";
        getline(cin, input);
        to_lowercase(input);
    
        if (input.compare("y") == 0) {
            break;
        } else if (input.compare("n") != 0) {
            cout << "Interpreted input as 'N'" << endl;
        }
    } while (true);

    for (auto const& idx: to_delete) {
        Test_Questions.remove_question(idx);
    }
    
    // Only save if indexes to delete are defined
    if (!to_delete.empty()) {
        Test_Questions.save();
    }
}

// Display welcome banner and load first menu
// TODO: linked list of menus to enable back() function
void welcome() {
    cout << BORDER << endl;
    cout << WELCOME_BANNER << endl;
    cout << "\n" << BORDER << endl;
    Test_Questions.load();
    Menu_Engine(MAIN_MENU, MAIN_MENU_SIZE);
}
