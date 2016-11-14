/*
 * Even Fibonacci numbers
 * Problem 2
 * Published on Friday, 19th October 2001, 06:00 pm; Solved by 496546; Difficulty rating: 5%
 *
 * Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:
 *
 * 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
 *
 * By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
 */
#include <array>
#include <cstdint>
#include <iostream>
#include <string>

int main()
{
    std::array<std::uint32_t,4000> fibs;
    std::uint32_t maxValue = 4000000;

    fibs[0] = 1;
    fibs[1] = 1;

    std::uint32_t currentIndex = 1;
    while (true)
    {
        std::uint32_t rez = fibs[currentIndex] + fibs[currentIndex - 1];
        if (rez >= maxValue)
        {
            break;
        }
        currentIndex++;
        fibs[currentIndex] = rez;
    }

    std::uint32_t evenSum = 0;
    for (std::uint32_t i = 1; i <= currentIndex; ++i)
    {
        std::uint32_t value = fibs[i];
        if ((value % 2) == 0)
        {
            evenSum += value;
        }
    }

    std::cout << "evenSum = " << evenSum << std::endl;
}
