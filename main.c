#include <stdio.h>
#include "bn.h"

int main() {
	bn* big_number; 
	bn_init_int(big_number, 10);

	bn_delete(big_number);
	return 0;
}