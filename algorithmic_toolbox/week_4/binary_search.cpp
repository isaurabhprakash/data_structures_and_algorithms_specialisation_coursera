#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<int> &a, int x)
{

    int low = 0;
    int high = a.size() - 1;
    int mid;

    while (low <= high)
    {

        mid = (low + high) / 2;

        if (a[mid] == x)
            return mid;

        if (a[mid] < x)
        {

            // Search in the right sub-array
            low = mid + 1;
        }
        else
        {

            // Search in the left sub-array
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++)
    {
        std::cin >> a[i];
    }
    int m;
    std::cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i)
    {
        std::cin >> b[i];
    }
    for (int i = 0; i < m; ++i)
    {
        std::cout << binary_search(a, b[i]) << ' ';
    }
}