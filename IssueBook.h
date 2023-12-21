#pragma once
#include<iostream>
#include<fstream>
using namespace std;
class Issuebook
{
private:
	string fbid;
	string fsid;
	string bid;
	string nop;
	string an;
	string isn;
	int in ;
public:
	void search();
	void search2();
	void issue();
	void validity();
	void lim_check();
};
