/*
Money Change Again Problem
Compute the minimum number of coins needed
to change the given value into coins with denominations 1, 3, and 4
*/
#include<iostream>
#include<vector>
#include<climits>

constexpr int coin_denominations[3] = { 4,3,1 }; // 1,3,4
constexpr int num_denominations = sizeof(coin_denominations) / sizeof(coin_denominations[0]);

std::vector<int>    minNumberOfCoins;

int get_change(int pSum) {

    int min_coins = INT_MAX;

    if (pSum == 0) {
        return 0;
    }

    // We do not know the minimum number of coins required to get the current sum
    if (!minNumberOfCoins[pSum]) {

        for (int i = 0; i < num_denominations; ++i) {

            int min_coins_cur_denomination = INT_MAX;

            if (pSum >= coin_denominations[i]) {

                min_coins_cur_denomination = get_change(pSum - coin_denominations[i]);

                // +1 as current coins is also picked up 
                if (min_coins_cur_denomination + 1 < min_coins) {

                    min_coins = min_coins_cur_denomination + 1;
                }
            }
        }
        minNumberOfCoins[pSum] = min_coins;
    }

    return minNumberOfCoins[pSum];
}

int main() {

    int m;

    std::cin >> m;

    minNumberOfCoins.resize(m + 1, 0);
    std::cout << get_change(m) << '\n';
}