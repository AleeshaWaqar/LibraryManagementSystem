#pragma once
#include<iostream>
#include<fstream>
using namespace std;
class Person{
	protected:
		string name; 
};
class DataIO{
	protected:
	ifstream input1;
	ofstream output1;	
};
class Student:public Person,public DataIO
{
private:
	string sid;        //Student ID.
	string dname;       //Degree name.
	string sem;         // Semester.
	string nib;         //NO. Of Issued books.
public:
	void add();
	void modify();
	void search();
	void Delete();
};
