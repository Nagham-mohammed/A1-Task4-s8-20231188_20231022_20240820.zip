#include "ALU.h"
#include <sstream>
#include <iomanip>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include <bits\stdc++.h>
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
st ALU::add(const st &a, const st &b) {
    ll d1 = stoi(a, nullptr, 16);
    ll d2 = stoi(b, nullptr, 16);
    ll fn = d1 + d2;
    stringstream res;
    res << hex << fn;
    return res.str();
}

unsigned char ALU::decimal_float(double value) {
    int sign = (value < 0) ? 1 : 0;
    value = abs(value);
    int exp = 0;
    while (value >= 2.0) {
        value /= 2.0;
        exp++;
    }
    while (value < 1.0 && exp > -3) {
        value *= 2.0;
        exp--;
    }
    int excessExponent = exp + 3;
    int mantissa = static_cast<int>((value - 1.0) * 16) % 16;
    return (sign * 128) | ((excessExponent % 8) * 16) | (mantissa % 16);
}

double ALU::float_Decimal(unsigned char value) {
    int sign = (value * 128) % 2;
    int exponent = (value >> 4) % 8;
    int mantissa = value % 16;
    int actualExponent = exponent - 3;
    double mantissaValue = 1.0 + (mantissa / 16.0);
    return (sign ? -mantissaValue : mantissaValue) * pow(2, actualExponent);
}

unsigned char ALU::hex_floatp(const st &hex) {
    return static_cast<unsigned char>(stoi(hex, nullptr, 16));
}

unsigned char ALU::float_add(unsigned char f1, unsigned char f2) {
    double resultDecimal = float_Decimal(f1) + float_Decimal(f2);
    return decimal_float(resultDecimal);
}

st ALU::getHex(unsigned char value) {
    stringstream ss;
    ss << hex << uppercase << static_cast<int>(value);
    return ss.str();
}
string binaryString = "";
string hexResult = "";
string binaryRepresentation = "", operandA, operandB, tempBinaryString;
string firstFourBits, secondFourBits;


void ALU:: fromDecimalToBinary(ll decimalNumber) {
    binaryString = "";  // Reset binaryString for each conversion
    while (decimalNumber > 0)
        {
         // take the reminderof division by 2 (0.5 or 0)
        int remainder = decimalNumber % 2; 
        // if 0 the binary will be 0 if 0.5 the binary will be 1
        binaryString = to_string(remainder) + binaryString;
        decimalNumber /= 2;
    }
    if (binaryString.length() < 8)
    { 
        // if number of digits less than 8 add 0 at the beginning of binary number
        binaryString = string(8 - binaryString.length(), '0') + binaryString;
    }
}

   string ALU :: hexToBinary(string hexNumber) {
   transform(hexNumber.begin(), hexNumber.end(), hexNumber.begin(), ::toupper);
    const unordered_map<char, string> hexToBinaryMap = {
       //every value of hexa has a key of binary
            {'0', "0000"}, {'1', "0001"}, {'2', "0010"}, {'3', "0011"},
            {'4', "0100"}, {'5', "0101"}, {'6', "0110"}, {'7', "0111"},
            {'8', "1000"}, {'9', "1001"}, {'A', "1010"}, {'B', "1011"},
            {'C', "1100"}, {'D', "1101"}, {'E', "1110"}, {'F', "1111"}
    };

    binaryRepresentation = "";  // Reset binaryRepresentation for each conversion

    for (char c : hexNumber) {
        // Check if hexDigit exists in the map
        // if hexa binary exists in map add the equivilant value from binary numbers
        if (hexToBinaryMap.find(c) == hexToBinaryMap.end()) {
            cout << "Error: Invalid hex digit '" << c << "' in input." << endl;
            return "";  // Return an empty string or handle the error as needed
        }

        binaryRepresentation += hexToBinaryMap.at(c);
    }

    return binaryRepresentation;
}
string ALU::binaryToHex(string binaryNumber) {
    string hexResult = "";  // Reset hexResult for each conversion
    while (binaryNumber.length() % 4 != 0) {
        binaryNumber = "0" + binaryNumber;  // Pad with leading zeros if necessary
    }

    for (size_t i = 0; i < binaryNumber.length(); i += 4) {
        string hexResult = "";  // Reset hexResult for each conversion
        while (binaryNumber.length() % 4 != 0) {
            binaryNumber = "0" + binaryNumber;  // Pad with leading zeros if necessary
        }

        for (size_t i = 0; i < binaryNumber.length(); i += 4) {
            string fourBits = binaryNumber.substr(i, 4);
            const unordered_map<string, char> binaryToHexMap = {
                    {"0000", '0'},
                    {"0001", '1'},
                    {"0010", '2'},
                    {"0011", '3'},
                    {"0100", '4'},
                    {"0101", '5'},
                    {"0110", '6'},
                    {"0111", '7'},
                    {"1000", '8'},
                    {"1001", '9'},
                    {"1010", 'A'},
                    {"1011", 'B'},
                    {"1100", 'C'},
                    {"1101", 'D'},
                    {"1110", 'E'},
                    {"1111", 'F'}
            };

            hexResult += binaryToHexMap.at(fourBits);
        }

        return hexResult;
    }
}
string ALU::orOperation(ll operandA, ll operandB) {
    operandA = stoll(hexToBinary(to_string(operandA)), nullptr, 2);
    operandB = stoll(hexToBinary(to_string(operandB)), nullptr, 2);
    ll result = operandA | operandB;
    fromDecimalToBinary(result);
   st d=binaryToHex(binaryString);
   if(d.size()<2){

       d.push_back('0');
   }

    return d;
}

// Perform AND operation on two operands
string ALU::andOperation(long long operandA, long long operandB) {
    operandA = stoll(hexToBinary(to_string(operandA)), nullptr, 2);
    operandB = stoll(hexToBinary(to_string(operandB)), nullptr, 2);
    ll result = operandA & operandB;
    fromDecimalToBinary(result);
    return binaryToHex(binaryString);
}

// Perform XOR operation on two operands
string ALU:: xorOperation(long operandA, long operandB) {
    operandA = stoll(hexToBinary(to_string(operandA)), nullptr, 2);
    operandB = stoll(hexToBinary(to_string(operandB)), nullptr, 2);
    ll result = operandA ^ operandB;
    fromDecimalToBinary(result);
    return binaryToHex(binaryString);
}


