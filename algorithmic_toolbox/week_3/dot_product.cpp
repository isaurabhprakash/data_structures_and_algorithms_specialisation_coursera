#include <iostream>
#include <vector>
#include <algorithm>

long long max_dot_product(std::vector<int> a, std::vector<int> b)
{

  long long result = 0;

  std::sort(a.begin(), a.end(), std::greater<int>());
  std::sort(b.begin(), b.end(), std::greater<int>());

  for (size_t i = 0; i < a.size(); i++)
  {
    result += ((long long)a[i]) * b[i];
  }

  return result;
}

int main()
{
  size_t n;
  std::cin >> n;
  
  std::vector<int> a(n), b(n);
  
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  
  std::cout << max_dot_product(a, b) << std::endl;
}