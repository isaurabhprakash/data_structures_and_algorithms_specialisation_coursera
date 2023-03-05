#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(std::vector<int> &numbers)
{
	long long result;
	std::sort(numbers.begin(), numbers.end(), std::greater<int> ());

	result = (long long)numbers[0] * numbers[1];
	return result;
}

int main()
{
	int n;

	std::cin >> n;

	std::vector<int> numbers(n);
	for (int i = 0; i < n; ++i)
	{
		std::cin >> numbers[i];
	}

	std::cout << MaxPairwiseProduct(numbers) << "\n";
	return 0;
}