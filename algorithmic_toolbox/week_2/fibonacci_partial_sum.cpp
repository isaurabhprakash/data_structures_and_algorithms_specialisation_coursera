#include <iostream>

constexpr int pisano_10 = 60;

int get_fibonacci_partial_sum(long long from, long long to)
{
    long long sum = 0;
    long long current = 0;
    long long next = 1;
    long long new_current = 0;

    from = from % pisano_10;
    to = to % pisano_10;

    if (to < from)
        to += pisano_10;

    for (long long i = 0; i <= to; ++i) {

        if (i >= from)
            sum = (sum + current) % 10;

        new_current = next;
        next = next + current;
        current = new_current % 10;
    }

    return sum;
}

int get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

void StressTest()
{
    for (int i = 0; i < 30; ++i) {

        int num1 = rand() % 50;
        int num2 = num1 + rand() % 50;
        int ans1 = get_fibonacci_partial_sum(num1, num2);
        int ans2 = get_fibonacci_partial_sum_naive(num1, num2);

        if (ans1 != ans2) {

            std::cout << "num  : " << num1 << std::endl;
            std::cout << "num  : " << num2 << std::endl;
            std::cout << "ans1 : " << ans1 << std::endl;
            std::cout << "ans2 : " << ans2 << std::endl;
            std::cout << "\n";
        }
    }
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum(from, to) << '\n';

    // Testing code
    //StressTest();
}