// implementation file: gen.cpp
#define _CRT_SECURE_NO_WARNINGS
#include "systemc.h"
#include "adder.h"

void adder::add()
{
	int res, i1, i2;
	while(true)
	{
		do wait(); while(ready_a_b.read() != true);
		i1 = a.read();
		i2 = b.read();
		cout << "\na: " << i1;
		cout << "\nb: " << i2;
		res = i1 + i2;
		s.write(res);
		ready_s.write(true);
		wait();
		ready_s.write(false);
	}

}
