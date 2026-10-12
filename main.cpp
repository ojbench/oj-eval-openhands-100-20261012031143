#include <iostream>
#include <vector>
#include <cmath>

// Function to calculate the sum of proper divisors of n
long long sumOfProperDivisors(long long n) {
    if (n == 1) return 0;  // 1 has no proper divisors
    
    long long sum = 1;  // 1 is always a proper divisor
    long long sqrtN = sqrt(n);
    
    // Check divisors from 2 to sqrt(n)
    for (long long i = 2; i <= sqrtN; i++) {
        if (n % i == 0) {
            sum += i;  // i is a divisor
            
            // If i is not the square root, add the corresponding divisor (n/i)
            if (i != n / i) {
                sum += n / i;
            }
        }
    }
    
    return sum;
}

int main() {
    int m;
    std::cin >> m;
    
    std::vector<long long> numbers(m);
    for (int i = 0; i < m; i++) {
        std::cin >> numbers[i];
    }
    
    for (int i = 0; i < m; i++) {
        long long sum = sumOfProperDivisors(numbers[i]);
        if (sum == numbers[i]) {
            std::cout << "1\n";
        } else {
            std::cout << "0\n";
        }
    }
    
    return 0;
}