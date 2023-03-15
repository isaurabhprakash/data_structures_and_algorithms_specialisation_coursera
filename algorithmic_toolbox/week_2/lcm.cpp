#include <iostream>

/**
 * lcm(a,b) X gcd(a,b) = a*b
 * 
 * However, a*b may be longer than LONG_MAX.
 * 
 * Hence we are using the following for computation
 * 
 * lcm(a,b) = (a/gcd(a,b))*b
 *  where a is the larger of a and b
*/
long long gcd(int a, int b)
{
	if (b == 0)
		return a;

	return gcd(b, a % b);
}

long long lcm(int a, int b) 
{
	long	max_num = std::max(a, b);
	long	min_num = std::min(a, b);
	
	max_num = max_num / gcd(a, b);
		
	return max_num * min_num;
}

int main() {
	int a, b;
	std::cin >> a >> b;
	std::cout << lcm(a, b) << std::endl;
	return 0;
}