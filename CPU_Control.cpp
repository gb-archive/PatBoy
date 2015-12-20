#include "CPU.h"


//////////////////////////////// CPU CONTROL COMMANDS
short CPU::opcode0x76() {
    halt = true;
    return 4;
}

short CPU::opcode0xF3() {
    interruptPendingDisabled = true;
    return 4;
}

short CPU::opcode0xFB() {
    interruptPendingEnabled = true;
    return 4;
}

short CPU::opcode0x3F() {
    toggleFlag(CARRY_FLAG);
    clearFlag(HALF_CARRY_FLAG);
    clearFlag(ADD_SUB_FLAG);
    return 4;
}// ccf -00c cy = cy xor 1

short CPU::opcode0x37() {
    raiseFlag(CARRY_FLAG);
    clearFlag(HALF_CARRY_FLAG);
    clearFlag(ADD_SUB_FLAG);
    return 4;
}// scf -001 cy = 1


short CPU::opcode0x00() {
    //NOP
    return 4;
}

/////////////////////////////////////////////// STOP
short CPU::opcode0x10() {
    incrementProgramCounter();
    return 4;
}

short CPU::invalidOpcode() {
    return 0;
}