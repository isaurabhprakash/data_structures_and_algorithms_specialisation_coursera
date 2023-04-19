#include <algorithm>
#include <iostream>
#include <vector>
#include<algorithm>

int binary_search(const std::vector<int>& a, int pLeft, int pRight, int x, bool pSearchLeft)
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

    if (foundndx != -1)
    {
        if (pSearchLeft) {

            if (foundndx) {
                
                if (a[foundndx - 1] == x)
                {

                    return binary_search(a, 0, foundndx - 1, x, true);
                }
            }
        }
        else {

            if (foundndx != a.size() - 1) {

                if (a[foundndx + 1] == x) {

                    // Search right
                    return binary_search(a, foundndx + 1, a.size() - 1, x, false);
                }

            }
        }
    }

    return foundndx;
}

int get_majority_element(std::vector<int>& a) {

    int mid;
    int left_most_idx;
    int right_most_idx;

    std::sort(a.begin(), a.end());

    mid = (a.size ()-1) / 2;

    if ((a[mid] != a[mid - 1]) && (a[mid] != a[mid + 1]))
        return 0;
    
    left_most_idx = binary_search(a, 0, mid, a[mid], true);
    right_most_idx = binary_search(a, mid, a.size () - 1 , a[mid], false);

    if (((right_most_idx - left_most_idx) + 1) > a.size() / 2)
        return 1;

    return 0;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cin >> a[i];
    }
    std::cout << get_majority_element(a)<< '\n';
}