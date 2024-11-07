#include "CPU.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define vi vector<int>
#define vll vector<ll>
#define vss vector<string>
#define el '\n'
#define pb push_back
#define st string
#define clos 3
#define an &&
#define loop for (int i=0;i<n;i++)

using namespace std;

CPU::CPU() : cu(mem, reg, alu) {}

void CPU::read_file(st &filename) {
        ifstream myfile(filename);
        if (!myfile) {
//            perror("Error opening file");
            cout<<"\nINVALID file or empty one!\n";
            return;
        }

        ll id = cu.get_pc();
        string line;
        bool hasC000 = false;

        while (getline(myfile, line)) {
            istringstream iss(line);
            string instruction;
            while (iss >> instruction) {
                if (instruction.size() == 4) {
                    store(id, instruction);
                    if (instruction == "C000") {
                        hasC000 = true;
                    } else {
                        hasC000 = false;
                    }
                } else {
                    cout << "Invalid instruction: " << instruction << el;
                }
            }
        }
        myfile.close();
        if (!hasC000) {
            store(id, "C000");
        }
    }

void CPU::store(ll &i, const st &s) {
    st first_memory_value = s.substr(0, 2);
    st second_memory_value = s.substr(2, 2);
    mem.set_memoryvalue(i, first_memory_value);
    i++;
    mem.set_memoryvalue(i, second_memory_value);
    i++;
}

void CPU::execute() {
    cu.execute();
}
bool CPU::execute_stepbystep(){
    return cu.execute_stepbystep();
}
void CPU::print_memory() {
    mem.print();
}

void CPU::print_regester() {
    reg.print();
}

void CPU::set_pc(ll &value) {
    cu.set_pc(value);
}

ll CPU::get_pc() {
    return cu.get_pc();
}