#pragma once
#include <Windows.h>



struct LogicGates {
	//take two inputs, even if it's a not we'll take two but use a by default
	bool a, b; // we only want 1 byte - 1 & 0

	LogicGates(bool a, bool b) : a(a), b(b) {};

	bool OR()
	{

		LogicGates* inpt1 = new LogicGates(a, a); //first nand gate shares the same input for a
		LogicGates* inpt2 = new LogicGates(b, b); //second nand gate shares the same input for b
		LogicGates* return_nand = new LogicGates(inpt1->NAND(), inpt2->NAND()); //last nand gate uses the input 1 and input 2 for a return value

		return return_nand->NAND();

	}

	

	bool AND()
	{ return (a & b); }

	bool NOT()
	{ return !a; }

	bool XOR()
	{ return (a ^ b); }

	bool NOR()
	{ return !OR(); }

	bool NAND()
	{ return !AND(); }

};