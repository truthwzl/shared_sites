#include <stdlib.h>
#include <stdio.h>
#include "api.h"
int add(VM* vm,int x, int y) 
{
	return vm->x+vm->y+x*y;
}
