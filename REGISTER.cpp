#include "REGISTER.h"
#include <iomanip>

REGISTER::REGISTER() : regester(size) {
    for (int i = 0; i <= 15; i++) {
        regester[i] = {i, "00"};
    }
}

void REGISTER::set_regester(ll a, st value) {
    if (a <= 15 && a >= 0)
        regester[a] = {a, value};
    else
        cout << "invalid address for the register" << endl;
}

st REGISTER::get_regvalue(ll a) {
    if (a <= 15 && a >= 0)
        return regester[a].second;
    else
        cout << "invalid address for the register" << endl;
    return "";
}

void REGISTER::print() {
    cout << "Register Contents:" << endl << endl;
    cout << "Register | Value" << endl;
    cout << "-----------------" << endl;
    for (auto it : regester) {
        cout << setw(8) << it.first << " | " << it.second << endl;
    }
    cout << "-----------------" << endl;
}
