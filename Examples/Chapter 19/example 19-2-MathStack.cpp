// Implementation file for the MathStack class
#include "example 19-2-MathStack.h"

//***********************************************
// Member function add. add pops                *
// the first the two values off the stack and   *
// adds them. The sum is pushed onto the stack. *
//***********************************************

void MathStack::add()
{
	int num, sum;

	// Pop the first two values off the stack.
	pop(sum);
	pop(num);

	// Add the two values, store in sum.
	sum += num;

	// Push sum back onto the stack.
	push(sum);
}

//****************************************
// Member function sub. sub pops the     *
// first two values off the stack. The   *
// second value is substracted from the  *
// first value. The difference is pushed *
// onto the stack.                       *
//****************************************

void MathStack::sub()
{
	int num, diff;

	// Pop the first two values oof the stack.
	pop(diff);
	pop(num);

	// Substract num from diff.
	diff -= num;

	// Push diff back onto the stack.
	push(diff);
}