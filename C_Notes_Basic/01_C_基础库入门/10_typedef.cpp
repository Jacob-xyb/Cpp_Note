#include <stdio.h>
#include "C_Basic_main.h"


void func_typedef_rename() {
	typedef int five_ints[5];
	five_ints x = { 1, 2, 3, 4, 5 };
}

