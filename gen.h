// header file: gen.h
SC_MODULE( gen ) {
	// Ports
	sc_in_clk clk;
	sc_in<int> s;
	sc_in<bool> ready_s;
	
	sc_out<int> a;
	sc_out<int> b;
	sc_out<bool> ready_a_b;

	// Process functionnality
	void generate_a_b();

	// Construtor
	SC_CTOR( gen ) {
		SC_CTHREAD(generate_a_b, clk.pos());
	}
};
