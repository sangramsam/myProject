#include "LString.h"
void LString::printStdRule()
{
	for(int i = 0; i < StdRule.size(); i++)
		StdRule[i]->print();
}