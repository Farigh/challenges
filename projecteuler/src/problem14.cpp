/*
 * Longest Collatz sequence
 *
 * The following iterative sequence is defined for the set of positive integers:
 *
 * n → n/2 (n is even)
 * n → 3n + 1 (n is odd)
 *
 * Using the rule above and starting with 13, we generate the following sequence:
 * 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
 *
 * It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms.
 * Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
 *
 * Which starting number, under one million, produces the longest chain?
 *
 * NOTE: Once the chain starts the terms are allowed to go above one million.
 */
#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <stack>

int main()
{
    const std::uint64_t maxStartingNumber = 1000000;
    std::uint64_t longestChain = 0;
    std::uint64_t longestChainNumber = 1;

    // key = number, value = chain length
    // Using unordered_map over regular map devides the execution time by 2
    std::unordered_map<std::uint64_t, std::uint64_t> alreadyEncountered = { { 1, 1 } };

    for (std::uint64_t i = 2; i < maxStartingNumber; ++i)
    {
        std::uint64_t currentNumber = i;
        std::stack<std::uint64_t> valuesStack;
        while (true)
        {
            if (alreadyEncountered.find(currentNumber) != alreadyEncountered.end())
            {
                std::uint64_t currentChain = valuesStack.size() + alreadyEncountered[currentNumber];

                if (currentChain > longestChain)
                {
                    longestChain = currentChain;
                    longestChainNumber = i;
                }
                break;
            }

            valuesStack.push(currentNumber);

            // Compute next number
            if ((currentNumber % 2) == 0)
            {
                currentNumber /= 2;
            }
            else
            {
                currentNumber *= 3;
                currentNumber++;
            }
        }

        // Pop each values for storage
        std::uint64_t chainSize = alreadyEncountered[currentNumber];
        while (! valuesStack.empty())
        {
            chainSize++;
            const std::uint64_t value = valuesStack.top();
            alreadyEncountered.insert({ value, chainSize });
            valuesStack.pop();
        }
    }

    std::cout << longestChainNumber << std::endl;
}
