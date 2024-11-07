#ifndef CPU_H
#define CPU_H
#include "MEMORY.h"
#include "REGISTER.h"
#include "ALU.h"
#include "CU.h"
#include <string>
#define ll long long

using namespace std;

class CPU {
private:
    MEMORY mem;

    REGISTER reg;
    ALU alu;
    CU cu;

public:

    CPU();

    void read_file(st &filename);
    void store(ll &index, const st &instruction);
    void execute();
    bool execute_stepbystep();
    void print_memory();
    void print_regester();
    void set_pc(ll &value);
    ll get_pc();
};

#endif // CPU_H