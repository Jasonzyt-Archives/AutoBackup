/* FILENAME = Main.h */
#pragma once
#ifndef _MAIN_H_
#define _MAIN_H_
#include <iostream>
#include <string>
#include <time.h>
#include <sstream>
#include <stdio.h>
#include "operate_config.del.h"
#include "getConfig.h"
#pragma warning(disable:4996)

using namespace std;

//Variable Declaration
//Function Declaration
string getTime();
string editZIPFilename(string outputfilename);
int _PR(int PRtype, string text);
string getCmdStr(string p1/*OPP*/, string p2/*TP*/, string p3/*OPF*/);
//string getConfig(string configfile, string key);
string getConfig(string configfile, string key, string defaultvaule);
const char* StringToChar(string inputStr);
int StringToInt(string str);
bool findFile(string filename);

#endif
