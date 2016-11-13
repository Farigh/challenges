/*
 * Sum square difference
 * Problem 6
 *
 * The sum of the squares of the first ten natural numbers is,
 * 1^2 + 2^2 + ... + 10^2 = 385
 *
 * The square of the sum of the first ten natural numbers is,
 * (1 + 2 + ... + 10)^2 = 55^2 = 3025
 *
 * Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
 *
 * Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
 */
#include <cstdint>
#include <iostream>
#include <string>

int main()
{
    std::uint64_t maxInt = 100;

    std::uint64_t squareSum = 1;
    std::uint64_t sum = 1;

    for (std::uint64_t i = 2; i <= maxInt; ++i)
    {
        squareSum += (i * i);
        sum += i;
    }

    std::uint64_t sumSquared = sum * sum;

    std::cout << sumSquared - squareSum << std::endl;
}