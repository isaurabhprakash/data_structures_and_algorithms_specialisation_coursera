#include<iostream>
#include<vector>
#include<cassert>

long long fibonacci(int n, std::vector<long long> & fib_table)
{
	assert(n >= 0);

	if (n <= 1)
		return n;

	if (!fib_table[n])
		fib_table[n] = fibonacci(n - 1, fib_table) + fibonacci(n - 2, fib_table);

	return fib_table[n];
}

int main()
{
	int	n;
	std::cin >> n;

	std::vector<long long>	fib_table(n+1);
	fib_table[0] = 0;
	fib_table[1] = 1;

	std::cout << fibonacci(n, fib_table) << std::endl;
}