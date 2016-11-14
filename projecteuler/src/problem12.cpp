/*
 * Highly divisible triangular number
 *
 * The sequence of triangle numbers is generated by adding the natural numbers.
 * So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first ten terms would be:
 *
 * 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
 *
 * Let us list the factors of the first seven triangle numbers:
 *
 *      1: 1
 *      3: 1,3
 *      6: 1,2,3,6
 *     10: 1,2,5,10
 *     15: 1,3,5,15
 *     21: 1,3,7,21
 *     28: 1,2,4,7,14,28
 *
 * We can see that 28 is the first triangle number to have over five divisors.
 *
 * What is the value of the first triangle number to have over five hundred divisors?
 */
#include <my_libs/MathUtils.h>

#include <cstdint>
#include <iostream>

std::uint32_t getTianglularNumber(std::uint32_t input)
{
    return (input + 1) * (input / 2) + ((input % 2) * ((input + 1) / 2));
}

int main()
{
    std::uint32_t targetFactorCount = 500;

    std::uint32_t iterations = 1;

    // While we are not done
    while (true)
    {
        std::uint32_t triangularNb = getTianglularNumber(iterations++);
        // Add 2 to the factor count (1 + self)
        std::uint64_t currentFactorCount = ::my::libs::MathUtils::getDeviders(triangularNb).size() + 2;

        if (currentFactorCount >= targetFactorCount)
        {
            std::cout << triangularNb << std::endl;
            break;
        }
    }
}
