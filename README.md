# FullAdder
C++ Implementation of a full adder that works with any amount of bits





# fulladder_struct [LINE 5]
bool sum;
bool cout;

This struct has two fields.
* Sum refers to the sum from the addition within a 1 bit fulladder. 
* cout refers to the carry output after the operation of the 1 bit fulladder has finished.


# fulladder_struct fulladder(...)
bool inp_a, bool inp_b, bool inp_c

This method has three parameters.
* inp_a refers to the first input value which I label as 'a'.
* inp_b refers to the second input value which I label as 'b'.
* inp_c refers to the carry input which I label as cIn. cIn is later assigned automatically from the cOut after the addition operation has completed for a single bit.

*This function is a single bit adder, we automate it later on to work with multiple bits.*
*for example, if we had two binary values where a = 0010 and b = 0011. We split it all up into single bits using the carry from each operation into the next adder parameter.*
*The return type for this method is fulladder_struct so we can organise the outputs easily*




