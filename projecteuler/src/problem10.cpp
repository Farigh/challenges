/*
 * Summation of primes
 *
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 *
 * Find the sum of all the primes below two million.
 */
#include <my_libs/MathUtils.h>

#include <vector>
#include <cstdint>
#include <iostream>

int main()
{
    std::uint64_t maxPrimeValue = 2000000;

    std::list<std::uint64_t> primes = ::my::libs::MathUtils::getPrimes(maxPrimeValue);

    std::uint64_t result = 0;
    for (std::uint64_t prime : primes)
    {
        result += prime;
    }

    std::cout << result << std::endl;
}
