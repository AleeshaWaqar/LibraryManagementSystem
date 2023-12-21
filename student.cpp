#include<iostream>
#include<fstream>
#include<sstream>
#include"student.h"
#include<conio.h>
#include<Windows.h>
using namespace std;
void Student::add()
{system("COLOR 8F");
	cout << "                                                         LIBARARY MANEGMENT SYSTEM" << endl;
	cout << endl;
	string sid, name, dname, sem, nib;
	cout << "\nATTRIBUTES OF STUDENT TO BE ADDED" << endl;
	cout << "STUDENT ID\t:";
	getline(cin>>ws,sid);
	cout << endl;
	cout << "NAME OF STUDENT\t:";
	getline(cin>>ws,name);
	cout << endl;
	cout << "DEGREE\t:";
	getline(cin>>ws,dname);
	cout << endl;
	cout << "SEMESTER\t:";
	getline(cin>>ws,sem);
	cout << endl;
	cout << "NUMBER OF BOOKS ISSUED\t:";
	getline(cin>>ws,nib);
	cout << endl;
	ofstream output1;
	output1.open("student.txt", ios::app);//to append
	if (!output1)
	{
		throw "STUDENT CAN NOT BE ADDED" ;
	}
	else
	{
		output1 << sid << "\n" << name << "\n" << dname << "\n" << sem << "\n" << nib << "\n";
		cout << endl;
		output1.close();
		cout << "\nSUCCESSFULLY ADDED" << endl;
	}
}
void Student::modify()
{system("COLOR 8F");
	cout << "                                                           LIBARARY MANEGMENT SYSTEM" << endl;
	cout << endl;
	string sid, name, dname, sem, nib, id;
	int found=0;
	ifstream input("student.txt");
	ofstream output("temp.txt");
	cout << "\nSTUDENT ID TO BE MODIFIED\t:";
	cin >> id;
	cout << endl;
	if (!input)
	{
	throw "FILE FAILED TO OPEN\n";
	}
	else
	{
		if (!output)
        {
            cout << "FILE FAILED TO OPEN" << endl;
            input.close();
            return;
        }

        while (getline(input, sid))
        {
            getline(input, name);
            getline(input, dname);
            getline(input, sem);
            getline(input, nib);
			if (id == sid)
			{   found=1;
				string sid, name, dname, sem, nib;
				cout << endl << "RECORD EXISTS!" << endl;
				cout << "\nATTRIBUTES OF THE STUDENT TO BE ADDED" << endl;
				cout << endl;
				cin.ignore();
				cout << "STUDENT ID\t:";
				getline(cin,sid);
				cin.ignore();
				cout << "NAME OF STUDENT\t:";
				getline(cin,name);
				cout << endl;
				cout << "DEGREE\t:";
				getline(cin,dname);
				cin.ignore();
				cout << "SEMESTER\t:";
				getline(cin,sem);
				cin.ignore();
				cout << "NUMBER OF BOOKS ISSUED\t:" << endl;
				getline(cin,nib);
				output << sid << "\n" << name << "\n" << dname << "\n" << sem << "\n" << nib << "\n";
				cout << endl;
				cout << "SUCCESSFULLY MODIFIED" << endl;
			}
			else
			{
				output << sid << "\n" << name << "\n" << dname << "\n" << sem << "\n" << nib << "\n";
			}
		}
		input.close();
		output.close();
		if (found==0)
		{
			cout << "RECORD DOES NOT EXIST" << endl;
		}
		remove("student.txt");
		rename("temp.txt", "student.txt");
	}
}


void Student::search()
{system("COLOR 8F");
    cout << "                                                           LIBRARY MANAGEMENT SYSTEM" << endl;
    cout << endl;
    string sid, name, dname, sem, nib;
    int found = 0;
    string x;
    cin.ignore();
    cout << "ID TO BE SEARCHED: ";
    getline(cin,x);
    cout << endl;
    ifstream input1("student.txt");
    if (!input1)
    {
        cout << "CAN NOT OPEN FILE" << endl;
        return;
    }
    while (getline(input1, sid))
    {
        getline(input1, name);
        getline(input1, dname);
        getline(input1, sem);
        getline(input1, nib);
        if (sid == x)
        {
            found = 1;
            cout << "RECOORD OF ENTERED ID" << endl;
            cout << "NAME: " << name << "\nDEPARTMENT: " << dname << "\nSEMESTER: " << sem << "\nISSUED BOOKS: " << nib << "\n";
        break;
		}
    }
    input1.clear();              // Clear the end-of-file state
    input1.seekg(0, ios::beg);
    input1.close();
    if (found == 0)
    {
        cout << "RECORD DOES NOT EXIST" << endl;
    }
}


void Student::Delete()
{system("COLOR 8F");
    cout << "                                                            LIBRARY MANAGEMENT SYSTEM" << endl;
    cout << endl;
    string sid, sn, dn, sen, nob;
    int found = 0;
    string fsid;
    cin.ignore();
    cout << "ID TO BE DELETED: ";
    getline(cin, fsid);
    ifstream input("student.txt");
    ofstream output("temp.txt");
    if (!input)
    {
        throw "FILES FAILED TO BE OPENED\n";
    }
    else
    {
        while (getline(input, sid))
        {
            getline(input, sn);
            getline(input, dn);
            getline(input, sen);
            getline(input, nob);
            if (sid == fsid)
            {
                found = 1;
                cout << "ID HAS BEEN DELETED" << endl;
            }
            else
            {
                output << sid << "\n" << sn << "\n" << dn << "\n" << sen << "\n" << nob << "\n";
            }
        }
        input.close();
        output.close();
        if (found == 0)
        {
            cout << "FAILED_RECORD DOES NOT EXIST" << endl;
            cout << endl;
        }
        remove("student.txt");
        rename("temp.txt", "student.txt");
    }
}

