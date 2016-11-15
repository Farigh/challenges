/*
 * Power digit sum
 *
 * 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 *
 * What is the sum of the digits of the number 2^1000?
 */
#include <my_libs/BigInt.h>

#include <cstdint>
#include <iostream>

using DataType = ::my::libs::BigInt<std::uint64_t, 30>;

int main()
{
    constexpr std::uint64_t targetPow = 1000;

    DataType result(2);
    std::uint64_t currentPow = 1;

    while (currentPow < targetPow)
    {
        DataType tmp = result;
        result.add(tmp);
        currentPow++;
    }

    // Lets sum all the numbers
    std::uint64_t sum = 0;
    for (std::uint8_t i = 0; i < result.getMaxInnerListSize(); ++i)
    {
        while (result.Data[i] != 0)
        {
            sum += (result.Data[i] % 10);
            result.Data[i] /= 10;
        }
    }

    std::cout << sum << std::endl;
}
