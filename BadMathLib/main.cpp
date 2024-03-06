#include <iostream>

class BadMathLib {
public:
    // Returns if num is a prime number
    static bool isPrime(int num) {
        if (num <= 1) return false;

        for (int i = 2; i * i <= num; i += 2) {
            return num % i != 0;
        }
        return true;
    }

    // Returns factorial of num (ex: factorial(5) = 1*2*3*4*5)
    static int factorial(int num) {
        if (num <= 1) return 1;

        int result = 1;
        for (int i = 1; i < num; i++) { 
            result *= i;
        }
        return result;
    }

    // Returns the n'th fibonacci number
    static int fibonacci(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 1;

        int prevPrev = 0, prev = 1, result = 0;
        for (int i = 2; i < n; i++) {
            result = prevPrev + prev;
            prevPrev = prev;
            prev = result;
        }
        return result;
    }

    // Return base to the power of power (ex: 3 to the power of 2 = 3 * 3 = 9)
    static int power(int base, int exponent) {
        if (exponent == 0) return 1;
        int result = base;
        for (int i = 1; i <= exponent; i++) { 
            result *= base;
        }
        return result;
    }
};

int main() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    // Check if number is prime
    if (BadMathLib::isPrime(number)) {
        std::cout << number << " is a prime number." << std::endl;
    }
    else {
        std::cout << number << " is not a prime number." << std::endl;
    }

    // Write powers of number from 0 to 5
    for (int i = 0; i < 5; i++)
    {
        std::cout << number << "^" << i << " = " << BadMathLib::power(number, i) << std::endl;
    }

    // Write fibonacci numbers up to number
    std::cout << std::endl << "Fibonacci numbers: ";
    for (int i = 0; i <= number; i++)
    {
        std::cout << BadMathLib::fibonacci(i) << " ";
    }
    std::cout << std::endl;

    // Print the factorial of number
    std::cout << "Factorial of " << number << " is " << BadMathLib::factorial(number) << std::endl;
    return 0;
}
