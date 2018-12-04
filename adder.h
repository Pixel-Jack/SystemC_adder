// header file: adder.h
SC_MODULE( adder) {
	// Ports
	sc_in_clk clk;
	sc_in<int> a;
	sc_in<int> b;
	sc_in<bool> ready_a_b;

	
	sc_out<int> s;
	sc_out<bool> ready_s;

	// Process functionnality
	void add();

	// Constructor
	SC_CTOR( adder ) {
		SC_CTHREAD(add, clk.pos());
	}
};

