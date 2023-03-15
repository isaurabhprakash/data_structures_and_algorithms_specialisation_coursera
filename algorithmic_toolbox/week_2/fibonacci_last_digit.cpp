#include<iostream>
#include<cassert>

long long get_fibonacci_last_digit(int n)
{
	assert(n >= 0);

	if (n <= 1)
		return n;

	int	cur, prev, prev_bef_change;

	// Since indexing starts from 0
	n = n - 1;

	prev = 0;
	cur = 1;

	while (n--) {

		prev_bef_change = prev;
		prev = cur;
		cur = (cur + prev_bef_change) % 10;
	}
	
	return cur;
}

int main()
{
	int	n;
	std::cin >> n;
	
	std::cout << get_fibonacci_last_digit(n) << std::endl;
}