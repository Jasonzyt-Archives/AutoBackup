/* FILENAME = Main.cpp */
#include<iostream>
#include<stdio.h>
#include<string>
#include<Windows.h>
#include"getConfig.h"
#include"Function.h"
#pragma warning(disable:6001)
#pragma warning(disable:6031)

using namespace std;

string opp, tp, bt;
int backuptime, backupms;

int main() {
	SetConsoleTitle(L"[NORMAL] 自动备份 AutoBackup");
	cout << "AutoBackup v1.6.9(Release x64) - Autobackup tool. Copyright (C)2020 JasonZYT" << endl;
	cout << "GitHub Repository:https://www.github.com/Jasonzyt/AutoBackup" << endl;
	_PR(0, "Starting...");
	_PR(0, "Reading Config...");
	string opp = getConfig("config.ini", "OutputPath", "backup\\");
	string tp = getConfig("config.ini", "TargetPath", "");
	string bt = getConfig("config.ini", "BackupTime", "60");
	int debug = StringToInt(getConfig("config.ini", "Debug", "0"));
	string opfn = getConfig("config.ini", "OutputFilname","%Y-%m-%d %H.zip");
	if ((findFile("./config.ini")) == false) {
		SetConsoleTitle(L"[ERROR][F001] 自动备份 AutoBackup");
		PRErr(0, "F001", "Can't Find Config File:config.ini. 找不到配置文件:config.ini");
		_PR(2, "Config Read Fail. 读取配置失败");
		getchar();
		throw "F001 Can't Find Config File";
		return 0;
	}
	else {
		_PR(0, "Config Read Success.");
	}
	string opf = editZIPFilename(opfn);
	int backuptime = StringToInt(bt);
	int backupms = backuptime * 60 * 1000;
	if (debug == 1)
	{
		ostringstream op;
		string d0 = getCmdStr(opp, tp, opf);
		op << "已读取配置:" << endl << "OutputPath=" << opp << endl << "TargetPath=" << tp << endl << "BackupTime=Every " << backuptime << " Minute(s)(Every " << backupms << " ms)" << endl << "OutputFilename=" << opf << "," << opfn << endl << "Debug=" << debug << endl << "Command : " << d0 << endl;
		string pr = op.str();
		_PR(3, pr);
	}
	if (tp=="")
	{
		SetConsoleTitle(L"[ERROR][F002] 自动备份 AutoBackup");
		PRErr(0, "F002", "Undefined TargetPath , Please Check config.ini. 未定义的目标文件夹 , 请检查config.ini");
		getchar();
		throw "F002 Undefined TargetPath.";
		return 0;
	}
	if (backuptime > 35791 || backuptime<1) 
	{
		SetConsoleTitle(L"[ERROR][F003] 自动备份 AutoBackup");
		PRErr(0, "F003", "Data Overflow. BackupTime参数不能大于35791分钟或小于1分钟 , 请修改config.ini");
		getchar();
		throw "F003 Data Overflow";
		return 0;
	}
	//!!不要超出35791分钟!!//
	cout << "已载入配置:" << endl << "OutputPath=" << opp << endl << "TargetPath=" << tp << endl << "BackupTime=Every " << backuptime << " Minute(s)(Every " << backupms << " ms)" << endl;
	while (1) 
	{
		string _opfn = editZIPFilename(opfn);
		_PR(0, "Starting Backup. 开始备份");
		_PR(0, "Starting Compress. 开始压缩");
		system((getCmdStr(opp,tp,_opfn)).c_str());
		_PR(0, "Backup Successful. 备份成功");
		Sleep(backupms);
	}
	return 0;
}