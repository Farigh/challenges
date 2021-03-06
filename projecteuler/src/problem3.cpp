/*
 * Largest prime factor
 * Problem 3
 *
 * The prime factors of 13195 are 5, 7, 13 and 29.
 *
 * What is the largest prime factor of the number 600851475143 ?
 */
/*
 * Largest prime factor
 * Problem 3
 *
 * The prime factors of 13195 are 5, 7, 13 and 29.
 *
 * What is the largest prime factor of the number 600851475143 ?
 */
#include <my_libs/MathUtils.h>

#include <iostream>
#include <list>
#include <string>

int main()
{
    long int inputNumber = 600851475143;

    std::list<long int> numberDeviders = ::my::libs::MathUtils::getDeviders(inputNumber);

    numberDeviders.sort();

    // As we need to find the largest prime factor, lets reverse iterate
    for (std::list<long int>::const_reverse_iterator it = numberDeviders.rbegin(); it != numberDeviders.rend(); ++it)
    {
        // A prime devider is a number with no deviders (besides itself and 1)
        if (::my::libs::MathUtils::getDeviders(*it).size() == 0)
        {
            std::cout << *it << std::endl;
            break;
        }
    }
}

