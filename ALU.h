#ifndef ALU_H
#define ALU_H

#include <string>
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
using st = string;


class ALU {
public:
    st add(const st &a, const st &b);
    unsigned char decimal_float(double value);
    double float_Decimal(unsigned char value);
    unsigned char hex_floatp(const st &hex);
    unsigned char float_add(unsigned char f1, unsigned char f2);
    st getHex(unsigned char value);
    void fromDecimalToBinary(long long decimalNumber);
    string hexToBinary(string hexNumber);
    string binaryToHex(string binaryNumber);
    string orOperation(long long  operandA, long long operandB);
    string andOperation(long long operandA, long long operandB);
    string xorOperation(long operandA, long operandB);
};

#endif // ALU_H