//
//  welcome.h
//  CA DMV
//
//  Created by Jake Day on 10/30/19.
//  Copyright © 2019 Jake Day. All rights reserved.
//

#ifndef welcome_h
#define welcome_h

#include "Menu.hpp"
#include "QuestionList.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

typedef vector<string> Menu_Options;

// Helper
void to_lowercase(string& str);
string unsigned_char_to_string(const unsigned char& c);

// Main Menu
void admin_mode();
void new_test();
void previous_test();
void quit();

// Admin Menu
void display_questions();
void add_question();
void remove_question();
void back();

void welcome();

// Menu options
static Menu_Item MAIN_MENU[] = {
    {1, "Go to admin interface", admin_mode},
    {2, "Take a new test", new_test},
    {3, "Display previous test results", previous_test},
    {4, "Quit", quit}
};

static Menu_Item ADMIN_MENU[] = {
    {1, "Display all questions", display_questions},
    {2, "Add a new question", add_question},
    {3, "Remove a question", remove_question},
    {4, "Back", back},
    {5, "Quit", quit},
};

static const unsigned int MAIN_MENU_SIZE = sizeof(MAIN_MENU) / sizeof(MAIN_MENU[0]);
static const unsigned int ADMIN_MENU_SIZE = sizeof(ADMIN_MENU) / sizeof(ADMIN_MENU[0]);

static Menu_Options OPTIONS { "Go to admin interface", "Take a new test", "Display previous test results" };
static QuestionList Test_Questions;

// Welcome banner text
static string WELCOME_BANNER =  "  _____            _____  __  ____      __  _____  _____            _____ _______ _____ _____ ______\n"
                                " / ____|   /\\     |  __ \\|  \\/  \\ \\    / / |  __ \\|  __ \\     /\\   / ____|__   __|_   _/ ____|  ____|\n"
                                "| |       /  \\    | |  | | \\  / |\\ \\  / /  | |__) | |__) |   /  \\ | |       | |    | || |    | |__\n"
                                "| |      / /\\ \\   | |  | | |\\/| | \\ \\/ /   |  ___/|  _  /   / /\\ \\| |       | |    | || |    |  __|\n"
                                "| |____ / ____ \\  | |__| | |  | |  \\  /    | |    | | \\ \\  / ____ \\ |____   | |   _| || |____| |____\n"
                                " \\_____/_/    \\_\\ |_____/|_|  |_|   \\/     |_|    |_|  \\_\\/_/    \\_\\_____|  |_|  |_____\\_____|______|";

static string BORDER =          "#####################################################################################################";

static string MENU =            "Please select an option below:";



#endif /* welcome_h */
