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
#include <iostream>
#include <list>
#include <string>

std::list<long int> getDeviders(long int inputNumber)
{
    std::list<long int> result;

    long int lowNumber = 1;
    long int highNumber = inputNumber;

    while (lowNumber < (highNumber - 1))
    {
        lowNumber++;
        if ((inputNumber % lowNumber) == 0)
        {
            highNumber = (inputNumber / lowNumber);
            result.push_back(lowNumber);
            result.push_back(highNumber);
        }
    }

    return result;
}

int main()
{
    long int inputNumber = 600851475143;

    std::list<long int> numberDeviders = getDeviders(inputNumber);

    numberDeviders.sort();

    // As we need to find the largest prime factor, lets reverse iterate
    for (std::list<long int>::const_reverse_iterator it = numberDeviders.rbegin(); it != numberDeviders.rend(); ++it)
    {
        // A prime devider is a number with no deviders (besides itself and 1)
        if (getDeviders(*it).size() == 0)
        {
            std::cout << *it << std::endl;
            break;
        }
    }
}

