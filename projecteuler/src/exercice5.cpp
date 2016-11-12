/*
 * Smallest multiple
 * Problem 5
 *
 * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 *
 * What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 */
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <string>

bool isPrime(int inputNumber)
{
    std::list<int> result;

    int lowNumber = 1;

    while (lowNumber < (inputNumber - 1))
    {
        lowNumber++;
        if ((inputNumber % lowNumber) == 0)
        {
            return false;
        }
    }

    return true;
}

std::list<int> getPrimes(int max)
{
    std::list<int> result;
    for (int i = 2; i <= max; ++i)
    {
        if (isPrime(i))
        {
            result.push_back(i);
        }
    }

    return result;
}

using FactorWeightMap = std::map<int, int>;

int main()
{
    long int highNum = 20;
    std::list<int> primes = getPrimes(highNum);

    // Key is the prime factor, value is the number of time it appears
    FactorWeightMap factors;

    for (int i = highNum; i > 1; --i)
    {
        int currentNumber = i;
        // Get numbers factors
        for (int prime : primes)
        {
            int currentPrimeWeight = 0;
            // count how many times it can devide our number
            while ((currentNumber % prime) == 0)
            {
                currentPrimeWeight++;
                currentNumber /= prime;
            }

            if (currentPrimeWeight == 0)
            {
                continue;
            }

            FactorWeightMap::iterator it = factors.find(prime);
            // Insert weight if it does not exists
            if (it == factors.end())
            {
                factors.insert(std::make_pair<>(prime, currentPrimeWeight));
            }
            else if (it->second < currentPrimeWeight)
            {
                factors[prime] = currentPrimeWeight;
            }
        }
    }

    int result = 1;
    // Finally multiply each prime factors powwered by their weight
    for (const FactorWeightMap::value_type& data : factors)
    {
        result *= std::pow(data.first, data.second);
    }

    std::cout << result << std::endl;
}