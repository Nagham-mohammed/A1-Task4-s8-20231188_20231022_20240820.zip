// main.cpp
#include <iostream>
#include "CPU.h"

using namespace std;

int main() {
    string filename;
    CPU c;
    ll n;
    while (true) {

        cout << " Main Menu " << el;
        cout << "------------" << el;
        cout << "1) Execute Program (Total print)" << el;
        cout << "2) Execute Program (print Step by Step)" << el;
        cout << "3) Exit" << el;
        cout << "Choose from 1-->3: ";
        string choice;
        cin >> choice;

        while (choice != "1" && choice != "2" && choice != "3" ) {
            cout << "Invalid choice. Please try again." << el;
            cout << "Enter another correct choice:";
            cin >> choice;
        }


        if (choice == "1") {
            cout << "Set the start of storing in memory: ";
                cin >> n;
                while(n%2!=0){
                    cout<<"Enter EVEN number please: ";
                    cin>>n;
                }
                c.set_pc(n);

            cout << "FIRST , Enter the file name (with .txt extension): ";
            cin >> filename;
            while (!regex_match(filename, regex(".*\\.txt$"))) {
                cout << "Invalid file extension! Please use a .txt file: " << el;
                cin >> filename;
            }
            c.read_file(filename);
            c.execute();
            c.print_regester();
            cout << el;
            c.print_memory();
            cout<<"Do you want to continue?\n 1.yes  2.no:  ";
            string k;
            cin>>k;
            while (k!="1"&&k!="2"){
                cout<<"INVALID choice\n ENTER new choice: ";
                cin>>k;
            }
            if(k=="1"){
                c.set_pc(n=1);
                continue;
            }else{
                return 0;
            }
        }else if (choice == "2") {
            cout << "Set the start of storing in memory: ";
            cin >> n;
            while(n%2!=0){
                cout<<"Enter EVEN number please: ";
                cin>>n;
            }
            c.set_pc(n);
            cout << "FIRST , Enter the file name (with .txt extension): ";
            cin >> filename;
            while (!regex_match(filename, regex(".*\\.txt$"))) {
                cout << "Invalid file extension! Please use a .txt file: " << el;
                cin >> filename;
            }
            c.read_file(filename);
            cout << "This is Step by Step Execution!" << el;
            char s='c';
            while (c.get_pc() < 256) {
                if (!c.execute_stepbystep()) {
                    cout << "Execution stopped cause of an invalid instruction or reach the end of the instructions" << el;
                    break;
                }
                cout << "---- Register ---- :" << el;
                c.print_regester();
                cout << "---- Memory State ----" << el;
                c.print_memory();

                // Ask user whether to continue to the next step
                cout << "Press 'c' to proceed to the next step or any other key to exit." << el;
                cin >> s;
                if (s != 'c') {break;
            }else{
                    n+=2;
                }
            }
            cout<<"Do you want to continue?\n 1.yes  2.no:  ";
            string k;
            cin>>k;
            while (k!="1"&&k!="2"){
                cout<<"INVALID choice\n ENTER new choice: ";
                cin>>k;
            }
            if(k=="1"){
                c.set_pc(n=1);
                continue;

            }else{
                return 0;
            }
        }
        else {
            cout << "Exiting program." << el;
            return 0;

        }


        c.set_pc(n);
        c.read_file(filename);
        c.execute();
        c.print_regester();
        c.print_memory();
        return 0;
    }
}
