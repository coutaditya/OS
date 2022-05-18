// C++ implementation of solution of Reader-Writer Problem using Binary Semaphore (Process Synchronisation)
#include <bits/stdc++.h>
using namespace ::std;

struct Semaphore
{
    bool s;

    Semaphore()
    {
        this->s = 1;
    }

    void down()
    {
        if (this->s == 0)
        {
            cout << "RESTRICTED!\n";
            return;
        }
        this->s = this->s - 1;
    }

    void up()
    {
        this->s = this->s + 1;
    }
};

// structure to represent the database
struct database
{
    string value;
};

int rc = 0; // Reader Count
bool read = false;

void Reader(Semaphore &mutex, Semaphore &db, database &d)
{

    mutex.down();
    rc++;
    if (rc == 1)
    {
        db.down();
    }
    mutex.up();

    // -------------------------------------------------------------------------
    cout << "Reader " << rc << " is reading the database\n";
    cout << "Value stored in the database = " << d.value << "\n\n";
    // -------------------------------------------------------------------------

    mutex.down();
    if(read){
        rc--;
    }
    if (rc == 0)
    {
        db.up();
    }
    mutex.up();
    read=true;
}

void Writer(Semaphore &mutex, Semaphore &db, database &d, string val)
{
    db.down();

    // --------------------------------------------------------------------------
    cout << "Writer is writing in the database\n";
    d.value = val;
    cout << "Value updated!\n\n";
    // --------------------------------------------------------------------------

    db.up();
    rc=0;
    read=false;
}

int main()
{
    cout << "SOLUTION TO READER-WRITER PROBLEM USING SEMAPHORE C++ IMPLEMENTATION\n";
    cout << "\nAditya Anand\n\nBranch: IT\n\n\n";

    Semaphore mutex; // Binary semaphore to synchronise incrementing of reader count
    Semaphore db;    // Binary semaphore to synchronise the access to a database

    database d;
    d.value = "0"; 

    cout << "Enter \n1 for reader\n2 for writer\n3 to exit\n";
    int n = 0;
    string val = "0";
    cin >> n;
    while (n == 1)
    {
        cout << "The database is empty\n\n";
        cout << "Enter \n1 for reader\n2 for writer\n3 to exit\n";
        // int n = 0;
        string val = "0";
        cin >> n;
        if(n==1){
            continue;
        }
        if (n == 2)
        {

            cout << "Enter the value you want to write:\n";
            cin >> val;
            Writer(mutex, db, d, val);
            n = 0;
            break;
        }
        else
        {
            cout << "Enter valid option.\n";
            n = 0;
            break;

        }
    }
    if (n == 2)
        {

            cout << "Enter the value you want to write:\n";
            cin >> val;
            Writer(mutex, db, d, val);
        
        }
        else
        {
            cout << "Enter valid option.\n";
        
        }

while (1)
{
    int n = 0;
    string val = "0";

    cout << "Enter  \n1 for reader\n2 for writer\n3 to exit\n";
    cin >> n;
    if (n == 1)
    {
        Reader(mutex, db, d);
    }
    else if (n == 2)
    {
        cout << "Enter the value you want to write: ";
        string val = "0";
        cin >> val;
        Writer(mutex, db, d, val);
    }
    else
        break;
}

return 0;
}