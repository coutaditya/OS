#include <iostream>
using namespace std;
#define MAX 50

int main(){
    cout << "SIMULATION OF PAGING TECHNIQUES C++ IMPLEMENTATION\n";
    cout << "Name: Aditya Anand\tRoll No.:20124009\t Branch: IT\n\n\n";

    int page[MAX], i, no_of_pgs, no_of_frms, pg_sz, off, pno;
    int choice = 0;

    cout << "Enter no of pages in memory: " << endl;
    cin >> no_of_pgs;
    cout << "Enter page size: " << endl;
    cin >> pg_sz;

    cout << "Enter no of frames: " << endl;
    cin >> no_of_frms;

    for (i = 0; i < no_of_frms; i++)
      page[i] = -1;
    cout << "\nEnter the page table\n";
    cout << "(Enter frame no as -1 if that page is not present in any frame)\n\n"
        << endl;
    cout << "\npageno\tframeno\n-------\t-------\n";

    for (i = 0; i < no_of_pgs; i++){
      cout << "\n\n"
          << i << "\t\t";
      cin >> page[i];
    }

    do{
      cout << "\n\nEnter the logical address(i.e,page no & offset): ";
      cin >> pno >> off;

      if (page[pno] == -1)
        cout << "\n\nThe required page is not available in any of frms";
      else
        cout << "Physical address (i.e, frame no and offset) : " << page[pno] << off << endl;
      cout << "\nDo you want to continue(1/0)?:";
      cin >> choice;

    }while (choice == 1);

    return 0;
}