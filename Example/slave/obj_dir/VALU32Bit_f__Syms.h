// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _VALU32Bit_f__Syms_H_
#define _VALU32Bit_f__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "VALU32Bit_f.h"

// SYMS CLASS
class VALU32Bit_f__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    VALU32Bit_f*                   TOPp;
    
    // CREATORS
    VALU32Bit_f__Syms(VALU32Bit_f* topp, const char* namep);
    ~VALU32Bit_f__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif // guard
