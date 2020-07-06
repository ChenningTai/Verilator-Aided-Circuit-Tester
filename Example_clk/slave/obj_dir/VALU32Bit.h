// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VALU32Bit_H_
#define _VALU32Bit_H_

#include "verilated.h"

class VALU32Bit__Syms;

//----------

VL_MODULE(VALU32Bit) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(CLK,0,0);
    VL_IN8(ALUControl,3,0);
    VL_OUT8(Zero,0,0);
    VL_IN(A,31,0);
    VL_IN(B,31,0);
    VL_OUT(ALUResult,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG(ALU32Bit__DOT__temp,31,0);
    VL_SIG(ALU32Bit__DOT__i,31,0);
    VL_SIG(ALU32Bit__DOT__x,31,0);
    VL_SIG(ALU32Bit__DOT__y,31,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(__Vclklast__TOP__CLK,0,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VALU32Bit__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VALU32Bit);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VALU32Bit(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VALU32Bit();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VALU32Bit__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VALU32Bit__Syms* symsp, bool first);
  private:
    static QData _change_request(VALU32Bit__Syms* __restrict vlSymsp);
    void _ctor_var_reset();
  public:
    static void _eval(VALU32Bit__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(VALU32Bit__Syms* __restrict vlSymsp);
    static void _eval_settle(VALU32Bit__Syms* __restrict vlSymsp);
    static void _sequent__TOP__1(VALU32Bit__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(VALU32Bit__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif // guard
