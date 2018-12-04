// implementation file: gen.cpp
#define _CRT_SECURE_NO_WARNINGS
#include "systemc.h"
#include "gen.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

void gen::generate_a_b()
{
	srand (time(NULL));
	while(true)
	{
		do wait(); while(ready_s.read() != true);
		cout << "\n\ts: " << s.read() << "\n";
		a.write(rand() % 101 );
		b.write(rand() % 101 );
		ready_a_b.write(true);
		wait();
		ready_a_b.write(false);
	}
}
