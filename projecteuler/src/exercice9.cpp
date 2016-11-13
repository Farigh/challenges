/*
 * Special Pythagorean triplet
 *
 * A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
 * a^2 + b^2 = c^2
 *
 * For example, 32 + 42 = 9 + 16 = 25 = 52.
 *
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 */
#include <vector>
#include <cstdint>
#include <iostream>

int main()
{
    int targetValue = 1000;

    std::uint16_t a = 1;
    std::uint16_t b = 2;
    std::uint16_t c = targetValue - a - b;
    for (std::uint16_t a = 1; a < (targetValue - 3); ++a)
    {
        for (std::uint16_t b = (a + 1); b < (targetValue - a - 1); ++b)
        {
            c = targetValue - a - b;

            // Verify a < b < c rule
            if (c <= b)
            {
                break;
            }

            // Verify a^2 + b^2 = c^2 rule
            if (((a * a) + (b * b)) == (c * c))
            {
                std::cout << std::to_string(a * b * c) << std::endl;
                return 0;
            }
        }
    }

    std::cout << "No Pythagorean triplet found for value : " << targetValue << std::endl;
}
