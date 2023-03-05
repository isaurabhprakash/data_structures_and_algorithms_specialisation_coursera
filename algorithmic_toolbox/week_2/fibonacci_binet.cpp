#include<iostream>
#include<cmath>

long long fibonacci(int n)
{
	return	(pow(((1 + sqrt(5)) / 2), n) - pow(((1 - sqrt(5)) / 2), n)) / sqrt(5);
}

int main()
{
	int	n;

	std::cin >> n;

	std::cout << fibonacci(n) << std::endl;
}