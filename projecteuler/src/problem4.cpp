/*
 * Largest palindrome product
 * Problem 4
 *
 * A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
 *
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */
#include <cstdint>
#include <iostream>
#include <list>
#include <string>

bool isPalendrome(std::uint64_t input)
{
    // Easier to check if a string is a palindrome
    std::string iStr = std::to_string(input);

    std::uint64_t size = iStr.size();
    std::uint64_t middle = size / 2;

    for (std::uint32_t i = 0; i < middle; i++)
    {
        if (iStr[i] != iStr[size - i - 1])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    std::uint64_t highNum = 999;
    std::uint64_t lowNum = 100;

    std::list<std::uint64_t> candidates;
    for (std::uint64_t i = highNum; i >= lowNum; --i)
    {
        // Assign i instead of highNum to avoid duplicates
        for (std::uint64_t j = i; j >= lowNum; --j)
        {
            candidates.push_back(i * j);
        }
    }

    candidates.sort();

    // As we need to find the largest one, lets reverse iterate
    for (std::list<std::uint64_t>::const_reverse_iterator it = candidates.rbegin(); it != candidates.rend(); ++it)
    {
        if (isPalendrome(*it))
        {
            std::cout << *it << std::endl;
            break;
        }
    }
}