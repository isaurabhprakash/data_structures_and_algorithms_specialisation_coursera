#include <iostream>
#include <vector>
#include <algorithm>

// Structure to hold cost per kg. This structure will be sorted based so that the item with highest cost per kg
// is at the lowest index. Since we will need to refer th same index in the weights vector, orignalIndex is also
// saved in this stucture
struct tCostPerKg {

    tCostPerKg (double pCostPerKg, int pIdx) {costPerKg = pCostPerKg; originalIndex = pIdx;};

    double  costPerKg;
    int     originalIndex;
};

// This is the comparator function taken by std::sort. It is used on a vector of tCostPerKg
bool sortCostPerKg (tCostPerKg pElem1, tCostPerKg pElem2)
{
    return pElem1.costPerKg > pElem2.costPerKg;
}

double get_optimal_value(int pCapacity, std::vector<int> pWeights, std::vector<int> pValues) {

    int                     idx;
    int                     weight_in_bag = 0;
    double                  value = 0.0;
    std::vector<tCostPerKg> per_kg_info; // Space Complexity : O(n)

    for (int i = 0 ; i < pWeights.size () ; ++i) {

        double          cost_per_kg = ((double)pValues[i])/pWeights[i];
        tCostPerKg      elem (cost_per_kg, i);

        per_kg_info.push_back(elem);
    }

    std::sort (per_kg_info.begin(), per_kg_info.end(), sortCostPerKg);

    idx = 0;

    while ((weight_in_bag < pCapacity) && (idx < pWeights.size ())) {

        int num_kg = std::min (pWeights[per_kg_info[idx].originalIndex], pCapacity-weight_in_bag);

        value += per_kg_info[idx].costPerKg * num_kg;
        weight_in_bag += num_kg;

        ++idx;
    }

    return value;
}

int main() {

    int n;
    int capacity;

    std::cin >> n >> capacity;

    std::vector<int> values(n);
    std::vector<int> weights(n);

    for (int i = 0; i < n; i++) {
        std::cin >> values[i] >> weights[i];
    }

    double optimal_value = get_optimal_value(capacity, weights, values);

    std::cout.precision(10);
    std::cout << optimal_value << std::endl;

    return 0;
}