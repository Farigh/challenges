/*
 * 10001st prime
 * Problem 7
 *
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
 *
 * What is the 10 001st prime number?
 */

#include <my_libs/MathUtils.h>

#include <cstdint>
#include <iostream>

int main()
{
    int targetIndex = 10001;

    // Handle 2 by hand so we can skip every even numbers
    std::uint64_t i = 3;
    targetIndex--;
    for (; targetIndex > 0; i += 2)
    {
        if (::my::libs::MathUtils::isPrime(i))
        {
            targetIndex--;
        }
    }

    // Discard the last "i += 2"
    std::cout << i - 2 << std::endl;
}