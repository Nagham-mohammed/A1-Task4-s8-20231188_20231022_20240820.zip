#ifndef CU_H
#define CU_H
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

#include "MEMORY.h"
#include "REGISTER.h"
#include "ALU.h"

class CU {
private:
    MEMORY &mem;
    REGISTER &reg;
    ALU &alu;
    ll pc;

public:
    CU(MEMORY &memory, REGISTER &regester, ALU &aluUnit);
    void set_pc(ll value);
    ll get_pc();
    void execute();
    bool execute_stepbystep();
};

#endif // CU_H