#include <stdio.h>
#include "bn.h"

int main() {
	bn* big_number = bn_new();
	bn* big_number2 = bn_init(big_number);
	
	bn_init_int(big_number, 10000000);
	bn_init_int(big_number2, 20);
	
	bn* sum = bn_add (big_number, big_number2);

	bn_delete(sum);
	bn_delete(big_number);
	bn_delete(big_number2);
	
	return 0;
}