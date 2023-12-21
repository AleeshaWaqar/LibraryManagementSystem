#include"ReturnBook.h"
using namespace std;
void return_book::ret_book()
{system("COLOR 8F");
    cout << "                                                      LIBRARY MANAGEMENT SYSTEM" << endl;
    cout << endl;

    int found = 0;
    ifstream input("issuancebook.txt", ios::in);
    ofstream output("temp.txt", ios::out);

    cout << "ID TO BE RETURNED: ";
    cin.ignore();
    getline(cin, rbid);
    cout << endl;

    if (!input)
    {
        throw "\nFILE DOES NOT EXIST";
    }
    else
    {
        string bid, nop, n, an, in;

        while (getline(input, bid))
        {
            getline(input, nop);
            getline(input, n);
            getline(input, an);
            getline(input, in);

            if (rbid.compare(bid) == 0)
            {
                found = 1;
                cout << "BOOK RETURNED SUCCESSFULLY" << endl;

                ofstream output1;
                output1.open("book.txt", ios::app);
                if (!output1)
                {
                    throw "FILE DOES NOT EXIST";
                }
                else
                {
                    output1 << bid << "\n" << nop << "\n" << n << "\n" << an << "\n" << in << "\n";
                    cout << "BOOK UPDATED SUCCESSFULLY" << endl;
                    output1.close();
                }
            }
            else
            {
                output << bid << "\n" << nop << "\n" << n << "\n" << an << "\n" << in << "\n";
            }
        }

        input.close();
        output.close();

        if (found == 0)
        {
            cout << "\nBOOK DOES NOT EXIST" << endl;
        }

        remove("issuancebook.txt");
        rename("temp.txt", "issuancebook.txt");
    }
}

