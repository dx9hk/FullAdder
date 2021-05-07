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



std::string anybit_fulladder(std::string inp1, std::string inp2, int max_bits)
{


	if (inp1.length() != max_bits && inp2.length() != max_bits)
	{
		//pad at least one of them
		int difference = max_bits - inp2.length();


		std::string res = [difference, inp2]() {
			std::string ret = "";
			std::string new_ret = "";
			for (int i = inp2.length() - 1; i >= 0; i--)
				ret += inp2[i];


			for (int i = 0; i <= difference - 1; i++)
				ret += "0";

			for (int i = ret.length() - 1; i >= 0; i--)
				new_ret += ret[i];


			return new_ret;
		}();
		inp2 = res;
	}

	if (inp1.length() > inp2.length() || inp1.length() < inp2.length())
	{
		[&inp1, &inp2]()
		{

			if (inp1.length() > inp2.length()) {
				//inp1 is longer than inp2
				//get the length of inp1 and find the difference between them
				int difference = inp1.length() - inp2.length();

				//pad the start with 0's of the shorter string

				std::string res = [difference, inp2]() {
					std::string ret = "";
					std::string new_ret = "";
					for (int i = inp2.length() - 1; i >= 0; i--) 
						ret += inp2[i];

					//std::printf("Reversed inp2 : %s\n", ret.c_str());

					for (int i = 0; i <= difference - 1; i++)
						ret += "0";

					//std::printf("Reversed inp2 with added padding : %s\n", ret.c_str());

					for (int i = ret.length() - 1; i >= 0; i--)
						new_ret += ret[i];

					//std::printf("reversed again : %s\n", new_ret.c_str());

					return new_ret;
				}();
				inp2 = res;


			}

			else if(inp2.length() > inp1.length()) {
				//inp2 is longer than inp1
				//get the length of inp2 and find the difference between them
				int difference = inp2.length() - inp1.length();

				//pad the start with 0's of the shorter string

				std::string res = [difference, inp1]() {
					std::string ret = "";
					std::string new_ret = "";
					for (int i = inp1.length() - 1; i >= 0; i--)
						ret += inp1[i];


					for (int i = 0; i <= difference - 1; i++)
						ret += "0";


					for (int i = ret.length() - 1; i >= 0; i--)
						new_ret += ret[i];


					return new_ret;
				}();
				inp1 = res;
			}
		}();



	}


	std::string ret = "";
	fulladder_struct *prevResult = new fulladder_struct(0,0);
	for (int i = max_bits - 1; i >= 0; i--)
	{
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


INT main()
{
	std::string result = anybit_fulladder("0100", "0100", 8);
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
