/*
 * Largest palindrome product
 * Problem 4
 *
 * A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
 *
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */
#include <iostream>
#include <list>
#include <string>

bool isPalendrome(long int i)
{
    // Easier to check if a string is a palindrome
    std::string iStr = std::to_string(i);

    int size = iStr.size();
    int middle = size / 2;

    for (int i = 0; i < middle; i++)
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
    long highNum = 999;
    long lowNum = 100;

    std::list<long int> candidates;
    for (long int i = highNum; i >= lowNum; --i)
    {
        // Assign i instead of highNum to avoid duplicates
        for (long int j = i; j >= lowNum; --j)
        {
            candidates.push_back(i * j);
        }
    }

    candidates.sort();

    // As we need to find the largest one, lets reverse iterate
    for (std::list<long int>::const_reverse_iterator it = candidates.rbegin(); it != candidates.rend(); ++it)
    {
        if (isPalendrome(*it))
        {
            std::cout << *it << std::endl;
            break;
        }
    }
}