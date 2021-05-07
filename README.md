# FullAdder
C++ Implementation of a full adder that works with any amount of bits
<br />
<br />

## FullAdderImpl.cpp


### fulladder_struct [LINE 5]
bool sum;
bool cout;

This struct has two fields.
* Sum refers to the sum from the addition within a 1 bit fulladder. 
* cout refers to the carry output after the operation of the 1 bit fulladder has finished.


### fulladder_struct fulladder(...) [LINE 15]
bool inp_a, bool inp_b, bool inp_c

This method has three parameters.
* inp_a refers to the first input value which I label as 'a'.
* inp_b refers to the second input value which I label as 'b'.
* inp_c refers to the carry input which I label as cIn. cIn is later assigned automatically from the cOut after the addition operation has completed for a single bit.

*This function is a single bit adder, we automate it later on to work with multiple bits.*
*for example, if we had two binary values where a = 0010 and b = 0011. We split it all up into single bits using the carry from each operation into the next adder parameter.*
*The return type for this method is fulladder_struct so we can organise the outputs easily*


### std::string anybit_fulladder(...) [LINE 29]
std::string inp1, std::string inp2, int max_bits

This method, also, has three parameters.
* inp1 refers to a string of the first binary value, for instance inp1 can equal "0011".
* inp2 refers to a string of the second binary value, for instance inp2 can equal "0001".
* max_bits refers to the max bit addition you'd like, for instance if max_bits equals 8 then it will be a 8 bit adder operation.

*This functions return type is std::string, this is because the output will be a string where the value is the output of 0011 + 0001."
*This function has validation to check if both the inputs are the same length, if not - it'll pad the start of the shorter string in order to match it. This'll allow the binary addition of "0010" and "010" to be interpreted as 2 + 2 rather than something irrelevant.*
*If both inputs are shorter than max_bits, it'll automatically pad both to be the length of max_bits + 1.*
*The reason it is max_bits + 1 and not just max_bits is so that it will not overflow if **all** bits are used. For example, with max_bits as 4 and both inp1 & inp2 are 1111, the result will be 11110*, the first value is the carry output.*

<br />
<br />

## LogicGates.hpp




