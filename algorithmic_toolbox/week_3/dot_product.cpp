#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool sort_to_make_largest_number(const std::string &pNum1, const std::string &pNum2)
{
  std::string string1 = pNum1 + pNum2;
  std::string string2 = pNum2 + pNum1;
  int num1 = std::stoi(string1);
  int num2 = std::stoi(string2);

  return (num1 > num2) ? true : false;
}

std::string largest_number(std::vector<std::string> pDigitsStringArr)
{
  std::string greatest_num;

  // Sort the array
  std::sort(pDigitsStringArr.begin(), pDigitsStringArr.end(), sort_to_make_largest_number);

  for (const auto &str : pDigitsStringArr)
    greatest_num += str;

  return greatest_num;
}

int main()
{
  int n;
  std::cin >> n;
  std::vector<std::string> a(n);
  for (size_t i = 0; i < a.size(); i++)
  {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}