// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VALU32Bit_test.h for the primary calling header

#include "VALU32Bit_test.h"    // For This
#include "VALU32Bit_test__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(VALU32Bit_test) {
    VALU32Bit_test__Syms* __restrict vlSymsp = __VlSymsp = new VALU32Bit_test__Syms(this, name());
    VALU32Bit_test* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VALU32Bit_test::__Vconfigure(VALU32Bit_test__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VALU32Bit_test::~VALU32Bit_test() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void VALU32Bit_test::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VALU32Bit_test::eval\n"); );
    VALU32Bit_test__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VALU32Bit_test* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
	VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
	_eval(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) {
	    // About to fail, so enable debug to see what's not settling.
	    // Note you must run make with OPT=-DVL_DEBUG for debug prints.
	    int __Vsaved_debug = Verilated::debug();
	    Verilated::debug(1);
	    __Vchange = _change_request(vlSymsp);
	    Verilated::debug(__Vsaved_debug);
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

void VALU32Bit_test::_eval_initial_loop(VALU32Bit_test__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) {
	    // About to fail, so enable debug to see what's not settling.
	    // Note you must run make with OPT=-DVL_DEBUG for debug prints.
	    int __Vsaved_debug = Verilated::debug();
	    Verilated::debug(1);
	    __Vchange = _change_request(vlSymsp);
	    Verilated::debug(__Vsaved_debug);
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

//--------------------
// Internal Methods

VL_INLINE_OPT void VALU32Bit_test::_sequent__TOP__1(VALU32Bit_test__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32Bit_test::_sequent__TOP__1\n"); );
    VALU32Bit_test* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at ALU32Bit_test.v:20
    if (((((((((VL_ULL(0) == VL_TIME_Q()) | (VL_ULL(2) 
					     == VL_TIME_Q())) 
	      | (VL_ULL(4) == VL_TIME_Q())) | (VL_ULL(6) 
					       == VL_TIME_Q())) 
	    | (VL_ULL(8) == VL_TIME_Q())) | (VL_ULL(0xa) 
					     == VL_TIME_Q())) 
	  | (VL_ULL(0xc) == VL_TIME_Q())) | (VL_ULL(0xe) 
					     == VL_TIME_Q()))) {
	if ((VL_ULL(0) == VL_TIME_Q())) {
	    vlTOPp->ALUControl = 0U;
	    vlTOPp->A = 2U;
	    vlTOPp->B = 2U;
	} else {
	    if ((VL_ULL(2) == VL_TIME_Q())) {
		vlTOPp->ALUControl = 1U;
		vlTOPp->A = 2U;
	    } else {
		if ((VL_ULL(4) == VL_TIME_Q())) {
		    vlTOPp->ALUControl = 3U;
		} else {
		    if ((VL_ULL(6) == VL_TIME_Q())) {
			vlTOPp->ALUControl = 9U;
		    } else {
			if ((VL_ULL(8) == VL_TIME_Q())) {
			    vlTOPp->ALUControl = 0xaU;
			} else {
			    if ((VL_ULL(0xa) == VL_TIME_Q())) {
				vlTOPp->ALUControl = 0xcU;
			    } else {
				vlTOPp->ALUControl 
				    = ((VL_ULL(0xc) 
					== VL_TIME_Q())
				        ? 0xdU : 0xeU);
			    }
			}
		    }
		}
	    }
	}
    } else {
	if ((VL_ULL(0x10) == VL_TIME_Q())) {
	    vlTOPp->ALUControl = 5U;
	    vlTOPp->B = 6U;
	} else {
	    vlTOPp->A = ((IData)(2U) + vlTOPp->A);
	    vlTOPp->B = ((IData)(3U) + vlTOPp->B);
	    vlTOPp->ALUControl = (0xfU & (IData)(VL_MODDIV_QQQ(64, (QData)(
									   VL_TIME_Q()), VL_ULL(0xf))));
	}
    }
    vlTOPp->CLK = (1U & (~ (IData)(vlTOPp->CLK)));
}

void VALU32Bit_test::_initial__TOP__2(VALU32Bit_test__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32Bit_test::_initial__TOP__2\n"); );
    VALU32Bit_test* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // INITIAL at ALU32Bit_test.v:17
    vlTOPp->CLK = 0U;
}

VL_INLINE_OPT void VALU32Bit_test::_sequent__TOP__3(VALU32Bit_test__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32Bit_test::_sequent__TOP__3\n"); );
    VALU32Bit_test* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at ALU32Bit.v:52
    if (((((((((0U == (IData)(vlTOPp->ALUControl)) 
	       | (1U == (IData)(vlTOPp->ALUControl))) 
	      | (2U == (IData)(vlTOPp->ALUControl))) 
	     | (3U == (IData)(vlTOPp->ALUControl))) 
	    | (4U == (IData)(vlTOPp->ALUControl))) 
	   | (5U == (IData)(vlTOPp->ALUControl))) | 
	  (6U == (IData)(vlTOPp->ALUControl))) | (7U 
						  == (IData)(vlTOPp->ALUControl)))) {
	if ((0U == (IData)(vlTOPp->ALUControl))) {
	    vlTOPp->ALUResult = (vlTOPp->A & vlTOPp->B);
	} else {
	    if ((1U == (IData)(vlTOPp->ALUControl))) {
		vlTOPp->ALUResult = (vlTOPp->A ^ vlTOPp->B);
	    } else {
		if ((2U == (IData)(vlTOPp->ALUControl))) {
		    vlTOPp->ALUResult = (vlTOPp->A 
					 + vlTOPp->B);
		} else {
		    if ((3U == (IData)(vlTOPp->ALUControl))) {
			vlTOPp->ALUResult = ((IData)(1U) 
					     + (vlTOPp->A 
						+ (~ vlTOPp->B)));
		    } else {
			if ((4U == (IData)(vlTOPp->ALUControl))) {
			    vlTOPp->ALUResult = (((1U 
						   & (vlTOPp->A 
						      >> 0x1fU)) 
						  != 
						  (1U 
						   & (vlTOPp->B 
						      >> 0x1fU)))
						  ? 
						 (((1U 
						    & (vlTOPp->A 
						       >> 0x1fU)) 
						   > 
						   (1U 
						    & (vlTOPp->B 
						       >> 0x1fU)))
						   ? 1U
						   : 0U)
						  : 
						 ((vlTOPp->A 
						   < vlTOPp->B)
						   ? 1U
						   : 0U));
			} else {
			    if ((5U == (IData)(vlTOPp->ALUControl))) {
				vlTOPp->ALUResult = 
				    (~ (vlTOPp->A | vlTOPp->B));
			    } else {
				if ((6U != (IData)(vlTOPp->ALUControl))) {
				    vlTOPp->ALUResult 
					= VL_DIV_III(32, vlTOPp->A, vlTOPp->B);
				}
			    }
			}
		    }
		}
	    }
	}
    } else {
	if (((((((((8U == (IData)(vlTOPp->ALUControl)) 
		   | (9U == (IData)(vlTOPp->ALUControl))) 
		  | (0xaU == (IData)(vlTOPp->ALUControl))) 
		 | (0xbU == (IData)(vlTOPp->ALUControl))) 
		| (0xcU == (IData)(vlTOPp->ALUControl))) 
	       | (0xdU == (IData)(vlTOPp->ALUControl))) 
	      | (0xeU == (IData)(vlTOPp->ALUControl))) 
	     | (0xfU == (IData)(vlTOPp->ALUControl)))) {
	    if ((8U == (IData)(vlTOPp->ALUControl))) {
		vlTOPp->ALUResult = ((0x1fU >= vlTOPp->B)
				      ? (vlTOPp->A 
					 << vlTOPp->B)
				      : 0U);
	    } else {
		if ((9U == (IData)(vlTOPp->ALUControl))) {
		    vlTOPp->ALUResult = (((1U & (vlTOPp->A 
						 >> 0x1fU)) 
					  != (1U & 
					      (vlTOPp->B 
					       >> 0x1fU)))
					  ? (((1U & 
					       (vlTOPp->A 
						>> 0x1fU)) 
					      > (1U 
						 & (vlTOPp->B 
						    >> 0x1fU)))
					      ? 0U : 1U)
					  : ((vlTOPp->A 
					      <= vlTOPp->B)
					      ? 0U : 1U));
		} else {
		    if ((0xaU == (IData)(vlTOPp->ALUControl))) {
			vlTOPp->ALU32Bit_test__DOT__uut__DOT__x 
			    = vlTOPp->B;
			vlTOPp->ALU32Bit_test__DOT__uut__DOT__temp = 0x20U;
			vlTOPp->ALU32Bit_test__DOT__uut__DOT__i = 0x1fU;
			while (VL_LTES_III(1,32,32, 0U, vlTOPp->ALU32Bit_test__DOT__uut__DOT__i)) {
			    if (((1U & (vlTOPp->A >> 
					(0x1fU & vlTOPp->ALU32Bit_test__DOT__uut__DOT__i))) 
				 == (1U & (vlTOPp->ALU32Bit_test__DOT__uut__DOT__x 
					   >> (0x1fU 
					       & vlTOPp->ALU32Bit_test__DOT__uut__DOT__i))))) {
				vlTOPp->ALU32Bit_test__DOT__uut__DOT__temp 
				    = ((IData)(0x1fU) 
				       - vlTOPp->ALU32Bit_test__DOT__uut__DOT__i);
				vlTOPp->ALU32Bit_test__DOT__uut__DOT__i = 0xfffffffeU;
			    }
			    vlTOPp->ALU32Bit_test__DOT__uut__DOT__i 
				= (vlTOPp->ALU32Bit_test__DOT__uut__DOT__i 
				   - (IData)(1U));
			}
			vlTOPp->ALUResult = vlTOPp->ALU32Bit_test__DOT__uut__DOT__temp;
		    } else {
			if ((0xbU == (IData)(vlTOPp->ALUControl))) {
			    vlTOPp->ALU32Bit_test__DOT__uut__DOT__y 
				= vlTOPp->A;
			    vlTOPp->ALU32Bit_test__DOT__uut__DOT__i 
				= (0x1fU & vlTOPp->B);
			    while (VL_LTS_III(1,32,32, 0U, vlTOPp->ALU32Bit_test__DOT__uut__DOT__i)) {
				vlTOPp->ALU32Bit_test__DOT__uut__DOT__y 
				    = ((0x20U & vlTOPp->B)
				        ? ((0x80000000U 
					    & (vlTOPp->ALU32Bit_test__DOT__uut__DOT__y 
					       << 0x1fU)) 
					   | (0x7fffffffU 
					      & (vlTOPp->ALU32Bit_test__DOT__uut__DOT__y 
						 >> 1U)))
				        : (0x7fffffffU 
					   & (vlTOPp->ALU32Bit_test__DOT__uut__DOT__y 
					      >> 1U)));
				vlTOPp->ALU32Bit_test__DOT__uut__DOT__i 
				    = (vlTOPp->ALU32Bit_test__DOT__uut__DOT__i 
				       - (IData)(1U));
			    }
			    vlTOPp->ALUResult = vlTOPp->ALU32Bit_test__DOT__uut__DOT__y;
			} else {
			    if ((0xcU == (IData)(vlTOPp->ALUControl))) {
				vlTOPp->ALUResult = 
				    (vlTOPp->A ^ vlTOPp->B);
			    } else {
				if ((0xdU == (IData)(vlTOPp->ALUControl))) {
				    vlTOPp->ALUResult 
					= (vlTOPp->A 
					   < vlTOPp->B);
				} else {
				    if ((0xeU == (IData)(vlTOPp->ALUControl))) {
					if ((0U == vlTOPp->B)) {
					    vlTOPp->ALUResult 
						= vlTOPp->A;
					} else {
					    if ((1U 
						 == vlTOPp->B)) {
						vlTOPp->ALUResult 
						    = vlTOPp->A;
					    }
					}
				    } else {
					vlTOPp->ALU32Bit_test__DOT__uut__DOT__y 
					    = vlTOPp->A;
					vlTOPp->ALU32Bit_test__DOT__uut__DOT__i 
					    = vlTOPp->B;
					while (VL_LTS_III(1,32,32, 0U, vlTOPp->ALU32Bit_test__DOT__uut__DOT__i)) {
					    vlTOPp->ALU32Bit_test__DOT__uut__DOT__y 
						= (
						   (0x80000000U 
						    & vlTOPp->ALU32Bit_test__DOT__uut__DOT__y) 
						   | (0x7fffffffU 
						      & (vlTOPp->ALU32Bit_test__DOT__uut__DOT__y 
							 >> 1U)));
					    vlTOPp->ALU32Bit_test__DOT__uut__DOT__i 
						= (vlTOPp->ALU32Bit_test__DOT__uut__DOT__i 
						   - (IData)(1U));
					}
					vlTOPp->ALUResult 
					    = vlTOPp->ALU32Bit_test__DOT__uut__DOT__y;
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
}

void VALU32Bit_test::_eval(VALU32Bit_test__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32Bit_test::_eval\n"); );
    VALU32Bit_test* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->sys_clk) ^ (IData)(vlTOPp->__Vclklast__TOP__sys_clk))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    if (((IData)(vlTOPp->CLK) & (~ (IData)(vlTOPp->__Vclklast__TOP__CLK)))) {
	vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__sys_clk = vlTOPp->sys_clk;
    vlTOPp->__Vclklast__TOP__CLK = vlTOPp->CLK;
}

void VALU32Bit_test::_eval_initial(VALU32Bit_test__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32Bit_test::_eval_initial\n"); );
    VALU32Bit_test* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__2(vlSymsp);
}

void VALU32Bit_test::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32Bit_test::final\n"); );
    // Variables
    VALU32Bit_test__Syms* __restrict vlSymsp = this->__VlSymsp;
    VALU32Bit_test* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VALU32Bit_test::_eval_settle(VALU32Bit_test__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32Bit_test::_eval_settle\n"); );
    VALU32Bit_test* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

VL_INLINE_OPT QData VALU32Bit_test::_change_request(VALU32Bit_test__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32Bit_test::_change_request\n"); );
    VALU32Bit_test* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VALU32Bit_test::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32Bit_test::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((sys_clk & 0xfeU))) {
	Verilated::overWidthError("sys_clk");}
}
#endif // VL_DEBUG

void VALU32Bit_test::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU32Bit_test::_ctor_var_reset\n"); );
    // Body
    sys_clk = VL_RAND_RESET_I(1);
    ALUControl = VL_RAND_RESET_I(4);
    A = VL_RAND_RESET_I(32);
    B = VL_RAND_RESET_I(32);
    ALUResult = VL_RAND_RESET_I(32);
    CLK = VL_RAND_RESET_I(1);
    ALU32Bit_test__DOT__uut__DOT__temp = VL_RAND_RESET_I(32);
    ALU32Bit_test__DOT__uut__DOT__i = VL_RAND_RESET_I(32);
    ALU32Bit_test__DOT__uut__DOT__x = VL_RAND_RESET_I(32);
    ALU32Bit_test__DOT__uut__DOT__y = VL_RAND_RESET_I(32);
    __Vclklast__TOP__sys_clk = VL_RAND_RESET_I(1);
    __Vclklast__TOP__CLK = VL_RAND_RESET_I(1);
}
