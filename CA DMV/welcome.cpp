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
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::find;
using std::distance;
using std::transform;

void admin_mode() { cout << "Entering admin interface" << endl; };
void new_test() { cout << "Starting new test" << endl; };;
void previous_test() { cout << "Displaying previous test results" << endl; };;

void add_options() {
    for (int i = 0; i < OPTIONS.size(); i++) {
        MENU.append("\n\t[" + to_string(i) + "]\t" + OPTIONS.at(i));
    }
}

void welcome() {
    cout << BORDER << endl;
    cout << WELCOME_BANNER << endl;
    cout << "\n" << BORDER << endl;
    //add_options();
    //cout << MENU << endl;
    Menu_Engine(MAIN_MENU, MENU_SIZE);
}
