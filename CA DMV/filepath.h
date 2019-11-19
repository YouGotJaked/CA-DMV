//
//  filepath.h
//  CA DMV
//
//  Created by Jake Day on 11/18/19.
//  Copyright © 2019 Jake Day. All rights reserved.
//

#ifndef filepath_h
#define filepath_h

#include <string>
#include <unistd.h>
#include <limits.h>

#ifdef _WIN32
#include <windows.h>
#endif

using std::string;

string cwd() {
#ifdef _WIN32
    char temp[MAX_PATH];
    return string(temp, GetModuleFileName(NULL, temp, PATH_MAX));
#else
    char temp[PATH_MAX];
    return ( getcwd(temp, sizeof(temp)) ? std::string( temp ) : std::string("") );
#endif
}

#ifdef _WIN32
static string QUESTION_FILE = "C:\Users\jday\source\CA-DMV-WIN\questions.json";
#else
static string QUESTION_FILE = ( cwd().find("jakeday") != string::npos ? "/Users/jakeday/questions.json" : "/Users/jday/questions.json");
#endif
#endif /* filepath_h */
