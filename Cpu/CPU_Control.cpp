#include "CPU.h"


//////////////////////////////// CPU CONTROL COMMANDS
short CPU::opcode0x76() {
    halt = true;
    return 0;
}

short CPU::opcode0xF3() {
    ime = false;
    return 4;
}

short CPU::opcode0xFB() {
    ime = true;
    return 4;
}

short CPU::opcode0x3F() {
    instructionSet->ccf(&AF.low);
    return 4;
}// ccf -00c cy = cy xor 1

short CPU::opcode0x37() {
    instructionSet->scf(&AF.low);
    return 4;
}// scf -001 cy = 1


short CPU::opcode0x00() {
    //NOP
    return 4;
}

/////////////////////////////////////////////// STOP
short CPU::opcode0x10() {
    incrementProgramCounter();
    return 0;
}

short CPU::invalidOpcode() {
    return 0;
}
