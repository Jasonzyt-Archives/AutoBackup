/* FILENAME = Main.cpp */
#include<iostream>
#include<stdio.h>
#include<string>
#include<Windows.h>
#include"head.h"
#pragma warning(disable:6001)
#pragma warning(disable:6031)

using namespace std;

string opp, tp, bt;
int backuptime, backupms;

int main() {
	SetConsoleTitle(L"自动备份 AutoBackup");
	cout << "AutoBackup v1.0.0(Release x64) - Autobackup tool. Copyright (C)2020 JasonZYT" << endl;
	_PR(0, "Starting...");
	string opp = getConfig("config.ini", "OutputPath");
	string tp = getConfig("config.ini", "TargetPath");
	string bt = getConfig("config.ini", "BackupTime");
	int backuptime = StringToInt(bt);
	int backupms = backuptime * 60 * 1000;
	string d0 = getZIPFilename();
	string d1 = getCmdStr(tp, opp, d0);
	cout << "[DEBUG]" << endl << "已读取配置:" << endl << "OutputPath=" << opp << endl << "TargetPath=" << tp << endl << "BackupTime=Every " << backuptime << " Minute(s)(Every " << backupms << " ms)" << endl << "Command : " << d1 << endl;
	if (opp == "")
	{
		opp = "backup\\";
	}
	if (tp=="")
	{
		_PR(2, "Undefined TargetPath , Please Check config.ini. 未定义的目标文件夹 , 请检查config.ini");
		getchar();
		return 0;
	}
	if (backuptime > 35791||backuptime<1) 
	{
		_PR(2, "BackupTime参数不能大于35791分钟或小于1分钟 , 请修改config.ini");
		getchar();
		return 0;
	}
	//!!不要超出35791分钟!!//
	cout << "已载入配置:" << endl << "OutputPath=" << opp << endl << "TargetPath=" << tp << endl << "BackupTime=Every " << backuptime << " Minute(s)(Every " << backupms << " ms)" << endl;
	while (1) {
		_PR(0, "Starting Backup. 开始备份");
		_PR(0, "Starting Compress. 开始压缩");
		string zipfilename = getZIPFilename();
		string cmdstr = getCmdStr(tp,opp,zipfilename);
		const char* c1 = cmdstr.c_str();
		system(c1);
		_PR(0, "Backup Successful. 备份成功");
		Sleep(backupms);
	}
	return 0;
}