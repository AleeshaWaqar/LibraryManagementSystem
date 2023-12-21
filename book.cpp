#include"book.h"
#include<fstream>
#include<iostream>
#include<string>
#include <sstream>
#include<conio.h>
#include<Windows.h>

using namespace std;
void book::create()
{system("COLOR 8F");
	cout << "LIBARARY MANEGMENT SYSTEM" << endl;
	cout << endl;
	string bid, nop, bn, an, in;
	cout << "ATTRIBUTES OF THE BOOK YOU WANT TO CREATE: " << endl;
	cout << endl;
	cout << "ID:";
	cin >> bid;
	cout << "NUMBER OF PAGES\t:";
	cin >> nop;
	cin.ignore();
	cout << "BOOK NAME\t:";
	getline(cin>>ws,bn);
	cout << "AUTHOR NAME\t:";
	getline(cin>>ws,an);
	cout << "ISSUER NAME\t:";
	getline(cin>>ws,in);
	ofstream output;
	output.open("book.txt", ios::app);
	if (!output)
	{
		throw "FILE CAN NOT BE OPENED";
	}
	else
	{
		output << bid << "\n" << nop << "\n" << bn << "\n" << an << "\n" << in << "\n";//writes data
		cout << endl;
		output.close();
		cout << "\nSUCCESSFULLY CREATED A BOOK" << endl;
	}
}
void book::modify()
{system("COLOR 8F");
    cout << "                                                            LIBRARY MANAGEMENT SYSTEM" << endl;
    cout << endl;

    string cid, bid, nop, bn, an, in;
    int found = 0;
    ifstream input("book.txt");
    ofstream output("temp.txt");

    cout << "ENTER THE BOOK ID YOU WANT TO MODIFY: ";
    cin >> cid;
    cout << endl;

    if (!input)
    {
        cout << "INPUT FILE FAILED TO OPEN" << endl;
    }
    else
    {
        if (!output)
        {
            cout << "OUTPUT FILE FAILED TO OPEN" << endl;
            input.close();
            return;
        }

        while (getline(input, bid))
        {
            getline(input, nop);
            getline(input, bn);
            getline(input, an);
            getline(input, in);

            if (bid == cid)
            {
                found = 1;
                cout << "ATTRIBUTES OF BOOK TO BE MODIFIED:" << endl;
                cout << "\nID: ";
                cin >> bid;
                cout << "NUMBER OF PAGES: ";
                cin >> nop;
                cout << "BOOK NAME: ";
                cin.ignore();
                getline(cin,bn);
                cout << "AUTHOR NAME: ";
                cin.ignore();
                getline(cin,an);
                cout << "ISSUER NAME: ";
                cin.ignore();
                getline(cin,in);

                output << bid << "\n" << nop << "\n" << bn << "\n" << an << "\n" << in << "\n";

                cout << "SUCCESSFULLY MODIFIED THE BOOK" << endl;
                cout << endl;
            }
            else
            {
                output << bid << "\n" << nop << "\n" << bn << "\n" << an << "\n" << in << "\n";
            }
        }

        input.close();
        output.close();

        if (found == 0)
        {
            cout << "\nCAN NOT MODIFY_THE BOOK DOES NOT EXIST" << endl;
            cout << endl;
        }

        remove("book.txt");
        rename("temp.txt", "book.txt");
    }
}

void book::search()
{system("COLOR 8F");
    cout << "                                                              LIBRARY MANAGEMENT SYSTEM" << endl;
    cout << endl;

    string bid, nop, bn, an, in;
    string searchId;
    int found = 0;

    cout << "ENTER THE BOOK ID TO BE SEARCHED: ";
    cin >> searchId;

    ifstream input("book.txt");
    if (!input)
    {
        cout << "FILE CAN NOT BE OPENED" << endl;
        return;
    }

    while (getline(input, bid))
    {
        getline(input, nop);
        getline(input, bn);
        getline(input, an);
        getline(input, in);	       
		 if (bid == searchId)
        {
            found = 1;
            cout << "RECORD:" << endl;
            cout << "BOOK ID: " << bid << endl;
            cout << "PAGES: " << nop << endl;
            cout << "BOOK NAME: " << bn << endl;
            cout << "AUTHOR NAME: " << an << endl;
            cout << "ISSUER NAME: " << in << endl;
            cout << endl;
            break;
        }
    }
  input.clear();              // Clear the end-of-file state
    input.seekg(0, ios::beg);
    input.close();

    if (found == 0)
    {
        cout << "THE ENTERED BOOK ID DOES NOT EXIST IN LIBRARY" << endl;
        cout << endl;
    }
}


void book::Delete()
{system("COLOR 8F");
    cout << "                                                       LIBRARY MANAGEMENT SYSTEM" << endl;
    cout << endl;
    string bid, nop, bn, an, in;
    string eid;
    int found = 0;
    cout << "ENTER BOOK ID TO BE DELETED: ";
    cin.ignore();
    getline(cin, eid);
    cout << endl;
    ifstream input("book.txt");
    ofstream output("temp.txt");
    if (!input)
    {
        cout << "FILE DOES NOT EXIST" << endl;
    }
    else
    {
        while (getline(input, bid))
        {
            getline(input, nop);
            getline(input, bn);
            getline(input, an);
            getline(input, in);
            if (bid == eid)
            {
                found = 1;
                cout << "\nTHE RECORD HAS BEEN DELETED" << endl;
            }
            else
            {
                output << bid << "\n" << nop << "\n" << bn << "\n" << an << "\n" << in << "\n";
            }
        }
        input.close();
        output.close();
        if (found == 0)
        {
            cout << "ID NOT FOUND_CAN NOT DELETE" << endl;
        }

        remove("book.txt");
        rename("temp.txt", "book.txt");
    }
}

