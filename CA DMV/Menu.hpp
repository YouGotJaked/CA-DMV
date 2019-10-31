//
//  Menu.hpp
//  CA DMV
//
//  Created by Jake Day on 10/30/19.
//  Copyright © 2019 Jake Day. All rights reserved.
//

#ifndef Menu_hpp
#define Menu_hpp

#include <string>

using std::string;

typedef void (*Menu_Processing_Function_Ptr)();

struct Menu_Item {
    unsigned int number;
    const char *text;
    Menu_Processing_Function_Ptr p_processing_fuction;
};

bool is_numeric(const string& str);
void to_lowercase(string& str);
void option_select(Menu_Item *p_menu, unsigned int quantity);
void Menu_Engine(Menu_Item *p_menu, unsigned int quantity);

#endif /* Menu_hpp */
