#include <iostream>

namespace global_const {

	constexpr int coin_1 = 1;
	constexpr int coin_5 = 5;
	constexpr int coin_10 = 10;
}

int find_number_of_coins(int& pAmount, int pCoinValue)
{
	int number_of_coins = 0;
	int amount_left = pAmount;

	while (amount_left >= pCoinValue) {

		amount_left = amount_left - pCoinValue;
		number_of_coins++;
	}

	// Set it to amount that is left to be covered with other set of coins
	pAmount = amount_left;

	return number_of_coins;
}


int get_change(int pRemainingAmount) {

	// Explanotory variables
	int	num_coin10, num_coin5, num_coin1;

	num_coin10 = find_number_of_coins(pRemainingAmount, global_const::coin_10);
	num_coin5 = find_number_of_coins(pRemainingAmount, global_const::coin_5);
	num_coin1 = find_number_of_coins(pRemainingAmount, global_const::coin_1);

	return num_coin10 + num_coin5 + num_coin1;
}

int main() {

	int m;
	std::cin >> m;
	std::cout << get_change(m) << '\n';
}