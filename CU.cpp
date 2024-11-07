#include "CU.h"
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
#include <iostream>

CU::CU(MEMORY &memory, REGISTER &regester, ALU &aluUnit)
        : mem(memory), reg(regester), alu(aluUnit), pc(0) {}

void CU::set_pc(ll value) {
    if (value >= 0 && value < 256)
        pc = value;
    else
        cout << "Invalid PC value" << endl;
}

ll CU::get_pc() {
    return pc;
}

void CU::execute() {
        while (pc < 256) {
            st instruction = mem.get_meoryvalue(pc) + mem.get_meoryvalue(pc + 1);
            if (instruction.size() < 4) {
                cout << "Invalid instruction" << endl;
                break;
            }

            ll check = stoi(instruction.substr(0, 1), nullptr, 16);
            ll ad1 = stoi(instruction.substr(1, 1), nullptr, 16);
            ll ad2 = stoi(instruction.substr(2, 2), nullptr, 16);
            ll regad1 = stoi(instruction.substr(2, 1), nullptr, 16);
            ll regad2 = stoi(instruction.substr(3, 1), nullptr, 16);

            if (check == 1) {  // Load immediate to register
                st val = mem.get_meoryvalue(ad2);
                reg.set_regester(ad1, val);
            } else if (check == 2) {  // Load direct value to register
                st val = instruction.substr(2, 2);
                reg.set_regester(ad1, val);
            } else if (check == 3) {  // Print from register to memory (screen if addr 0)
                st val = reg.get_regvalue(ad1);
                if (ad2 == 0) {
                    mem.set_memoryvalue(0,val);
                    char v = stoi(val, nullptr, 16);
                    cout << v;  // Display character
                    cout<<el;
                } else {
                    mem.set_memoryvalue(ad2, val);
                }
            } else if (check == 4) {  // Transfer between registers
                st val1 = reg.get_regvalue(regad1);
                reg.set_regester(regad2, val1);
            } else if (check == 5) {  // Add two registers and store result
                st val = alu.add(reg.get_regvalue(regad1), reg.get_regvalue(regad2));
                if (val.size() > 2) val.erase(0, val.size() - 2);  // Keep last two hex chars
                reg.set_regester(ad1, val);
            } else if(check==6)
            {
                st a=reg.get_regvalue(regad1);
                st b=reg.get_regvalue(regad2);
                unsigned char fp1 = alu.hex_floatp(a);
                unsigned char fp2 = alu.hex_floatp(b);
                unsigned char result = alu.float_add(fp1, fp2);
                st val= alu.getHex(result);
                reg.set_regester(ad1,val);
            }
            else if (check == 11) {  // Conditional jump if register equals R0
                st val = reg.get_regvalue(ad1);
                if (val == reg.get_regvalue(0)) {
                    pc = ad2 - 2;  // Adjust for increment after instruction
                }
            } else if (check == 7) {
                st val = alu.orOperation(stoll(reg.get_regvalue(regad1)), stoll(reg.get_regvalue(regad2)));
                reg.set_regester(ad1, val);  // Assuming set_register exists
            }

            else if (check == 8) {
                st val = alu.andOperation(stoll(reg.get_regvalue(regad1)), stoll(reg.get_regvalue(regad2)));
                reg.set_regester(ad1, val);  // Assuming set_register exists
            }

            else if (check == 9) {
                st val = alu.xorOperation(stoll(reg.get_regvalue(regad1)), stoll(reg.get_regvalue(regad2)));
                reg.set_regester(ad1, val);  // Assuming set_register exists
            }
            else if (check == 12) {  // Halt
                break;
            }

            pc += 2;  // Move to next instruction
        }
    }
bool CU::execute_stepbystep() {
    if (pc >= 256) {
        cout << "End of program memory reached." << endl;
        return false;
    }

    st instruction = mem.get_meoryvalue(pc) + mem.get_meoryvalue(pc + 1);
    if (instruction.size() < 4) {
        cout << "Invalid instruction" << endl;
        return false;
    }

    ll check = stoi(instruction.substr(0, 1), nullptr, 16);
    ll ad1 = stoi(instruction.substr(1, 1), nullptr, 16);
    ll ad2 = stoi(instruction.substr(2, 2), nullptr, 16);
    ll regad1 = stoi(instruction.substr(2, 1), nullptr, 16);
    ll regad2 = stoi(instruction.substr(3, 1), nullptr, 16);
    cout<<"the current instruction: "<<instruction<<endl;
    if (check == 1) {  // Load immediate to register
        cout<<"load from memory to register"<<el;
        st val = mem.get_meoryvalue(ad2);
        reg.set_regester(ad1, val);
    } else if (check == 2) {
        cout<<"load to register directly"<<el;
        st val = instruction.substr(2, 2);
        reg.set_regester(ad1, val);
    } else if (check == 3) {
        st val = reg.get_regvalue(ad1);
        if (ad2 == 0) {
            cout<<"Print from register to memory"<<el;
            mem.set_memoryvalue(0,val);
            char v = stoi(val, nullptr, 16);
            cout << "Memory updated: "<<v;  // Display character
            cout<<el;
        } else {
            cout<<"store the value from register to memory"<<el;
            mem.set_memoryvalue(ad2, val);
        }
    } else if (check == 4) {  // Transfer between registers
        cout<<"copy from register to another"<<el;
        st val1 = reg.get_regvalue(regad1);
        reg.set_regester(regad2, val1);
    } else if (check == 5) {
        cout<<"Add two registers and store result"<<endl;
        st val = alu.add(reg.get_regvalue(regad1), reg.get_regvalue(regad2));
        if (val.size() > 2) val.erase(0, val.size() - 2);  // Keep last two hex chars
        reg.set_regester(ad1, val);
    } else if(check==6)
    {
        cout<<"Add two registers(floating point) and store result"<<el;
        st a=reg.get_regvalue(regad1);
        st b=reg.get_regvalue(regad2);
        unsigned char fp1 = alu.hex_floatp(a);
        unsigned char fp2 = alu.hex_floatp(b);
        unsigned char result = alu.float_add(fp1, fp2);
        st val= alu.getHex(result);
        reg.set_regester(ad1,val);
    }
    else if (check == 11) {
        cout<<"Conditional jump if register equals R0"<<el;
        st val = reg.get_regvalue(ad1);
        if (val == reg.get_regvalue(0)) {
            pc = ad2 - 2;  // Adjust for increment after instruction
        }
    } else if (check == 7) {
        cout<<"OR function between two values in two registers"<<el;
        st val = alu.orOperation(stoll(reg.get_regvalue(regad1)), stoll(reg.get_regvalue(regad2)));
        reg.set_regester(ad1, val);  // Assuming set_register exists
    }

    else if (check == 8) {
        cout<<"AND function between two values in two registers"<<el;
        st val = alu.andOperation(stoll(reg.get_regvalue(regad1)), stoll(reg.get_regvalue(regad2)));
        reg.set_regester(ad1, val);  // Assuming set_register exists
    }

    else if (check == 9) {
        cout<<"XOR function between two values in two registers"<<el;
        st val = alu.xorOperation(stoll(reg.get_regvalue(regad1)), stoll(reg.get_regvalue(regad2)));
        reg.set_regester(ad1, val);  // Assuming set_register exists
    }
    else if (check == 12) {  // Halt
        return false;
    }

    pc += 2;  // Move to next instruction
    return true;
}






