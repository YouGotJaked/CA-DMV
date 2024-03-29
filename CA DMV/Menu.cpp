//
//  Menu.cpp
//  CA DMV
//
//  Created by Jake Day on 10/30/19.
//  Copyright © 2019 Jake Day. All rights reserved.
//

#include "Menu.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// Adapted from: https://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c
bool is_numeric(const string& str) {
    string::const_iterator it = str.begin();
    
    while (it != str.end() && std::isdigit(*it)) {
        it++;
    }
    
    return !str.empty() && it == str.end();
}

// Select a menu option based on the input
void option_select(Menu_Item *p_menu, unsigned int quantity) {
    unsigned int selection, i;
    string input;
    
    do {
        cout << "Enter selection:\t";
        getline(cin, input);
        
        if (is_numeric(input)) {
            selection = stoi(input, nullptr);
            
            for (i = 0; i < quantity; i++) {
                if (selection == p_menu[i].number) {
                    (p_menu[i].p_processing_fuction)();
                    break;
                }
            }
            
            if (i >= quantity) {
                cout << "Invalid selection." << endl;
            }
        } else {
            cout << "The input \'" << input << "\' was not recognized." << endl;
        }
    } while (true);
}

// Display the menu and its options
void Menu_Engine(Menu_Item *p_menu, unsigned int quantity) {
    for (unsigned int i = 0; i < quantity; i++) {
        cout << "\t[" << p_menu[i].number << "] " << p_menu[i].text << endl;
    }
    
    option_select(p_menu, quantity);
}
