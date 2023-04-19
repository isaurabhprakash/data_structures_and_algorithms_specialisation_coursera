#include <iostream>
#include <vector>

int binary_search(const std::vector<int> &a, int pLeft, int pRight, int x)
{
    int left = pLeft;
    int right = pRight;
    int mid;
    int foundndx;

    foundndx = -1;

    while (left <= right)
    {

        mid = (left + right) / 2;

        if (a[mid] == x)
        {

            foundndx = mid;
            break;
        }
        else if (a[mid] < x)
        {

            left = mid + 1;
        }
        else
        {

            right = mid - 1;
        }
    }

    if (foundndx && (foundndx != -1))
    {
        if (a[foundndx - 1] == x)
        {

            return binary_search(a, 0, foundndx - 1, x);
        }
    }

    return foundndx;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++)
    {
        std::cin >> a[i];
    }
    int m;
    std::cin >> m;
    std::vector<int> b(m);
    for (int i = 0; i < m; ++i)
    {
        std::cin >> b[i];
    }
    for (int i = 0; i < m; ++i)
    {
        std::cout << binary_search(a, 0, a.size() - 1, b[i]) << ' ';
    }
}