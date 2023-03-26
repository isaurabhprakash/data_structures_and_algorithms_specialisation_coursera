#include <iostream>
#include <vector>

/**
 * Here we are starting from the number 1 and then adding the valid candidates
 * to the summands vector till n/2. n/2 as any number beyond that can not be added
 * to  a greater number to obtain the sum.
 *
 * Now the problem is to find the set of numbers in such a way that the size of the set
 * is the largest. Following greedy method, we always try to pick the minimum possible summand.
 * Then we add that to the summand array, and the same process is repeated again for the remaining
 * sum.
 *
 * least_valid_summand : minimum possible summand
 * remainig_sum : sum left without least_valid_sumnmand
 *
 * Once we reach a summand which is greater than n/2, we can no longer find any other valid summand.
 * Hence this number itself is added to the summand.
 *
 * E.g :
 * n = 9
 * This will follow the pattern : (least_valid_summand, sum)
 * (1,9)
 * --->(2,8)
 * ------>(3,6) ---> here (2 *3 >= 3) -> hence 6 is the last valid candidate
 *
 * Hence the solution is 1,2,6
 *
*/
std::vector<int> optimal_summands(int n)
{

  int remaining_sum = n;
  int least_valid_summand = 1;
  std::vector<int> summands;

  while (true)
  {

    if (2 * least_valid_summand < remaining_sum)
    {

      summands.push_back(least_valid_summand);
      remaining_sum = remaining_sum - least_valid_summand;
      ++least_valid_summand;
    }
    else
    {

      summands.push_back(remaining_sum);
      break;
    }
  }

  return summands;
}

int main()
{
  int n;
  std::cin >> n;
  std::vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i)
  {
    std::cout << summands[i] << ' ';
  }
}