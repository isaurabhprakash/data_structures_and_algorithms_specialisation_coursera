#include <iostream>

constexpr int pisano_10 = 60;

int fibonacci_sum_last_digit(long long n) {

    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;
    long long old_previous;
    long long sum = 1;

    n = n % pisano_10;

    if (n <= 1)
        return n;

    for (long long i = 2; i <= n; ++i) {

        old_previous = previous;
        previous = current;

        current = (old_previous + current) % 10;

        sum = (sum + current) % 10;
    }

    return sum;
}

int fibonacci_sum_last_digit_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;
    long long sum = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

void StressTest()
{
    for (int i = 0; i < 30; ++i) {

        int num = rand() % 50;
        int ans1 = fibonacci_sum_last_digit(num);
        int ans2 = fibonacci_sum_last_digit_naive(num);

        if (ans1 != ans2) {

            std::cout << "num  : " << num<< std::endl;
            std::cout << "ans1 : " << ans1 << std::endl;
            std::cout << "ans2 : " << ans2 << std::endl;
            std::cout << "\n";
        }
    }
}

int main() {

    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_last_digit(n);

    // Testing code
    //StressTest();
}