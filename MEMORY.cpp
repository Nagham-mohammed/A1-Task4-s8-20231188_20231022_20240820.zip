// memory.cpp
#include "MEMORY.h"
#include <iomanip>

MEMORY::MEMORY() : cells(size) {
    for (int i = 0; i < size; i++) {
        cells[i] = {i, "00"};
    }
}

void MEMORY::set_memoryvalue(ll ad, st value) {
    if (ad >= 0 && ad <= 255)
        cells[ad].second = value;
    else
        cout << "invalid address for memory" << endl;
}

st MEMORY::get_meoryvalue(ll ad) {
    if (ad >= 0 && ad <= 255)
        return cells[ad].second;
    else
        cout << "invalid address for memory" << endl;
    return "";
}

void MEMORY::print() {
    cout << "Memory Contents:" << endl << endl;
    cout << "Address | Value" << endl;
    cout << "----------------" << endl;
    for (auto it : cells) {
        cout << setw(7) << it.first << " | " << it.second << endl;
    }
    cout << "----------------" << endl;
}