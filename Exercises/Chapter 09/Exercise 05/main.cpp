/*
5. Pointer Rewrite
The following function uses reference variables as parameters. Rewrite the function
so it uses pointers instead of reference variables, then demonstrate the function in a
complete program.
*/

#include <iostream>

int doSomething(int* x, int* y)
{
	int temp = *x;
	*x = *y * 10;
	*y = temp * 10;
	return *x + *y;
}

int main()
{
	using namespace std;

	int a = 10, b = 20;

	cout << "a = " << a << ", b = " << b << endl;
	
	int sum = doSomething(&a, &b);
	cout << "Sum = " << sum << endl;

	cout << "a = " << a << ", b = " << b << endl;

	return 0;
}