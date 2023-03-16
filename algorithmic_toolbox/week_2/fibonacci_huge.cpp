#include <iostream>

long long get_pisano_period(long long m)
{
    long long previous = 0;
    long long current = 1;
    long long old_prev;
    int pasino_period = 2; // has to be atleast 2

    if (m == 1)
        return 0;

    while (true) {

        old_prev = previous;
        previous = current;
        current = current + old_prev;
        current = current % m;

        if ((current == 0) && ((current + previous) == 1))
            return pasino_period;

        pasino_period++;
    }
}

unsigned long long get_fibonacci_huge(long long n, long long m) {

    if (m == 1)
        return 0;

    unsigned long long previous = 0;
    unsigned long long current = 1;
    unsigned long long old_prev;

    int pisano_period = get_pisano_period(m);

    n = n % pisano_period;

    if (n <= 1)
        return n;

    for (int i = 2; i <= n; ++i) {

        old_prev = previous;
        previous = current;
        current = current + old_prev;
        current = current % m;
    }

    return current % m;
}

int main() {

    long long n, m;

    std::cin >> n >> m;
    std::cout << get_fibonacci_huge(n, m) << '\n';
}