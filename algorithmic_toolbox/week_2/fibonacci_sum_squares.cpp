#include <iostream>

constexpr int pisano_10 = 60;
constexpr int square_digit[10] = {0,1,4,9,6,5,6,9,4,1};

int get_fibonacci_last_digit(long long n)
{

    if (n <= 1)
        return (int)n;

    int    cur, prev, prev_bef_change;

    // Since indexing starts from 0
    n = n - 1;

    prev = 0;
    cur = 1;

    while (n--) {

        prev_bef_change = prev;
        prev = cur;
        cur = (cur + prev_bef_change) % 10;
    }
    
    return cur;
}

int fibonacci_sum_squares (long long n)
{
    int fn,fm, sum;
    
    fn = get_fibonacci_last_digit(n % pisano_10);
    fm = get_fibonacci_last_digit((n-1) % pisano_10);
    
    sum = (fn + fm)* fn;
    
    return sum % 10;
}

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return (int)n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

void StressTest()
{
    for (int i = 0; i < 30; ++i) {

        int num = i /*rand() % 50*/;
        int ans1 = fibonacci_sum_squares(num);
        int ans2 = fibonacci_sum_squares_naive(num);

        if (ans1 != ans2) {

            std::cout << "num  : " << num << std::endl;
            std::cout << "ans1 : " << ans1 << std::endl;
            std::cout << "ans2 : " << ans2 << std::endl;
            std::cout << "\n";
        }
    }
}


int main() {
    
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares(n);
    
    // Testing Code
    //StressTest ();
}