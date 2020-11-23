/*
12. Ackermann's Function
Ackermann's Function is a recursive mathematical algorithm that can be used to
test how well a computer performs recursion. Write a function A(m, n) that solves
Ackermann's Function. Use the following logic in your function:

If m = 0 then return n + 1
If n = 0 then return A(m - 1, 1)
Otherwise,    return A(m - 1, A(m, n - 1))
*/

#include <iostream>

int Ackermann(int m, int n)
{
	if (m == 0)
		return n + 1;
	else if (n == 0)
		return Ackermann(m - 1, 1);
	else
		return Ackermann(m - 1, Ackermann(m, n - 1));
}

int main()
{
	int test1 = Ackermann(0, 0);
	int test2 = Ackermann(0, 1);
	int test3 = Ackermann(1, 1);
	int test4 = Ackermann(1, 2);
	int test5 = Ackermann(1, 3);
	int test6 = Ackermann(2, 2);
	int test7 = Ackermann(3, 2);

	std::cout << "Test #1: " << test1 << std::endl;
	std::cout << "Test #2: " << test2 << std::endl;
	std::cout << "Test #3: " << test3 << std::endl;
	std::cout << "Test #4: " << test4 << std::endl;
	std::cout << "Test #5: " << test5 << std::endl;
	std::cout << "Test #6: " << test6 << std::endl;
	std::cout << "Test #7: " << test7 << std::endl;

	return 0;
}