#define _CRT_SECURE_NO_WARNINGS
#include "systemc.h"
#include "adder.h"
#include "gen.h"

int main()
{

	sc_signal<int> a ( "Signal A" );
	sc_signal<int> b ( "Signal B" );
	sc_signal<int> s ( "Signal S" );
	sc_signal<bool> ready_a_b ( "Ready A and B");
	sc_signal<bool> ready_s ( "Ready S");

	
	sc_clock clock("Clock", 1000000000, 0.5, 0.0);
	
	adder adder1( "Adder 1" );
	adder1.clk(clock);
	adder1.a(a);
	adder1.b(b);
	adder1.s(s);
	adder1.ready_a_b(ready_a_b);
	adder1.ready_s(ready_s);
	
	gen gen1( "Gen 1" );
	gen1.clk(clock);
	gen1.a(a);
	gen1.b(b);
	gen1.s(s);
	gen1.ready_a_b(ready_a_b);
	gen1.ready_s(ready_s);

	a.write(1);
	b.write(2);
	ready_a_b.write(true);
	ready_s.write(false);

	sc_start(20, SC_SEC);

	return 0;



}
