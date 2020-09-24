#include <iostream>
#include <string>
#include <time.h>
#include <sstream>
#include <stdio.h>
#include <io.h>
#include <stdlib.h>
#include "operate_config.del.h"
#include "getConfig.h"
#include "Function.h"
#pragma warning(disable:4996)

using namespace std;

string getTime()
{
    time_t timep;
    time(&timep);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&timep));
    return tmp;
}

string editZIPFilename(string p5)
{
    time_t timepp;
    time(&timepp);
    char tmp[64];
    strftime(tmp, sizeof(tmp), p5.c_str(), localtime(&timepp));
    return tmp;
}

int _PR(int PRtype, string text)
{
    ostringstream v1;
    string time = getTime();
    if (PRtype == 0)
    {
        v1 << "[" << time << " INFO] " << text;
        cout << v1.str() << endl;
    }
    else if (PRtype == 1)
    {
        v1 << "[" << time << " WARN] " << text;
        cout << v1.str() << endl;
    }
    else if (PRtype == 2)
    {
        v1 << "[" << time << " ERROR] " << text;
        cout << v1.str() << endl;
    }
    else if (PRtype == 3)
    {
        v1 << "[" << time << " DEBUG] " << text;
        cout << v1.str() << endl;
    }
    return 0;
}

int PRErr(int ErrorType, string ErrorCode, string text)
{
    ostringstream v9;
    string time = getTime();
    if (ErrorType == 0)
    {
        v9 << "[" << time << " ERROR][FATAL][" << ErrorCode << "] " << text;
        cout << v9.str() << endl;
        return 1;
    }
    return 0;
}

string getCmdStr(string p1/*OPP*/, string p2/*TP*/, string p3/*OPF*/)
{
    ostringstream v2;
    /*ƴ���ַ��� ���������޸Ĵ˲���Ϊ7-Zip.exe��bandzip.exe
    *Bandzip
        v2 << "[BandzipĿ¼] c -y -r -fmt:zip \"" << p1 << p3 << "\" " << "\"" << p2 << "\" ";
    *7-Zip
        v2 << "[7-ZipĿ¼] a \"" << p1 << p3 << "\" " << "\"" << p2 << "\" -y -r";
    */

    /*The splicing string is modified to 7-Zip.exe or bandzip.exe
    *Bandzip
        v2 << "[Bandzip Folder] c -y -r -fmt:zip \"" << p1 << p3 << "\" " << "\"" << p2 << "\" ";
    *7-Zip
        v2 << "[7-Zip Folder] a \"" << p1 << p3 << "\" " << "\"" << p2 << "\" -y -r";
    */
    v2 << "bz.exe c -y -r -fmt:zip \"" << p1 << p3 << "\" " << "\"" << p2 << "\" ";
    string v3 = v2.str();
    return v3;
}

/*
string getConfig(string configfile, string key)
{
    operate_config conf(configfile);
    string r1=conf.getValue(key);
    return r1;
}
*/

string getConfig(string configfile, string key, string defaultvaule)
{
    Config conf(configfile);
    string r1 = conf.Read(key, defaultvaule/*Ĭ��ֵ*/);
    return r1;
}

int StringToInt(string str)
{
    int r2 = atoi(str.c_str());
    return r2;
}

bool findFile(string filename)
{
    ifstream f(filename.c_str());
    return f.good();
}
