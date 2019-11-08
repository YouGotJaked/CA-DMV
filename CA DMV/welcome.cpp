//
//  welcome.cpp
//  CA DMV
//
//  Created by Jake Day on 10/30/19.
//  Copyright © 2019 Jake Day. All rights reserved.
//

#include "welcome.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using std::string;
using std::to_string;
using std::flush;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::find;
using std::distance;
using std::transform;

// Adapted from: https://stackoverflow.com/questions/313970/how-to-convert-stdstring-to-lower-case
void to_lowercase(string& str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

void admin_mode() {
    cout << "\nEntering admin interface" << endl;
    Menu_Engine(ADMIN_MENU, ADMIN_MENU_SIZE);
}

void new_test() {
    cout << "\nStarting new test" << endl;
}

void previous_test() {
    cout << "\nDisplaying previous test results" << endl;
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

void add_question() {
    string input, q, c;
    Answers a;
    
    cout << "Question:\t";
    getline(cin, input);
    q = input;
    
    do {
        cout << "Add an answer:\t";
        getline(cin, input);
        a.push_back(input);
        
        cout << "Correct answer? [Y/N]\t";
        getline(cin, input);
        to_lowercase(input);
 
        if (input.compare("y") == 0 && c.empty()) {
            c = a.back();
        } else if (input.compare("n") != 0) {   // input is not Y or N
            cout << "c'mon man..." << endl;
        }
        
        cout << "Done? [Y/N]\t";
        getline(cin, input);
        to_lowercase(input);
 
        if (input.compare("y") == 0) {
            break;
        } else if (input.compare("n") != 0) {   // input is not Y or N
            cout << "c'mon man..." << endl;
        }
    } while (true);

    Test_Questions.add_question(Question(q, c, a));
}

void remove_question() {
    cout << "remove a question here" << endl;
}

void welcome() {
    cout << BORDER << endl;
    cout << WELCOME_BANNER << endl;
    cout << "\n" << BORDER << endl;
    Menu_Engine(MAIN_MENU, MAIN_MENU_SIZE);
}
