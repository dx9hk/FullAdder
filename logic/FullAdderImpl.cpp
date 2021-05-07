#include "LogicGates.hpp"
#include <string>




struct fulladder_struct
{
	bool sum;
	bool cout;

	fulladder_struct(bool sum, bool cout) : sum(sum), cout(cout) {};

};


fulladder_struct fulladder(bool inp_a, bool inp_b, bool inp_c)
{
	bool outp_d = LogicGates(inp_b, inp_c).XOR();
	bool outp_e = LogicGates(inp_b, inp_c).AND();
	bool outp_f = LogicGates(outp_d, inp_a).AND();
	bool outp_g = LogicGates(outp_f, outp_e).OR(); //cout
	bool outp_h = LogicGates(inp_a, outp_d).XOR(); //sum

	return fulladder_struct(outp_h, outp_g);

}



std::string fourbit_fulladder(const char* inp1, const char* inp2)
{
	std::string ret = "";
	fulladder_struct *prevResult = new fulladder_struct(0,0);
	for (int i = 3; i >= 0; i--)
	{
		//both strings are 4 bits so length = 4;
		fulladder_struct currRes = fulladder(static_cast<int>(inp1[i]) - 48, static_cast<int>(inp2[i]) - 48, prevResult->cout);
		ret += std::to_string(currRes.sum);
		*prevResult = currRes;

	}

	ret += std::to_string(prevResult->cout);


	return [ret]() {
		std::string new_ret = "";
		for (int i = ret.length() - 1; i >= 0; i--)
			new_ret += ret[i];

		return new_ret;
	}();

}
#include <math.h>

INT main()
{
	std::string result = fourbit_fulladder("0001", "0010");
	std::puts(result.c_str());
	
	std::printf("Binary to Decimal = %d\n", [result]() {

		std::string res = [result]() {
			std::string new_ret = "";
			for (int i = result.length() - 1; i >= 0; i--)
				new_ret += result[i];

			return new_ret;
		}();


		int total = 0;
		for (int i = res.length() - 1; i >= 0; i--)
		{
			if ((static_cast<int>(res[i]) - 48) == 1)
			{
				total += pow(2, i);
			}
		}

		return total;
		}());

	for (;;) {}
	return 0;
}