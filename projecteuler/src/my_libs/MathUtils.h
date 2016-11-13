#ifndef _MATH_UTILS_H_
# define _MATH_UTILS_H_

# include <cmath>
# include <list>

namespace my {
namespace libs {

class MathUtils
{
public:
    MathUtils();
    ~MathUtils() = default;

    template <typename InputType>
    static std::list<InputType> getDeviders(InputType inputNumber)
    {
        std::list<InputType> result;

        InputType lowNumber = 1;
        InputType highNumber = inputNumber;

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

    template <typename InputType>
    static std::list<InputType> getPrimes(InputType max)
    {
        std::list<InputType> result;

        // Handle 2 by hand so we can skip every even numbers
        if (max >= 2)
        {
            result.push_back(2);
        }

        for (InputType i = 3; i <= max; i += 2)
        {
            if (isPrime(i))
            {
                result.push_back(i);
            }
        }

        return result;
    }

    template <typename InputType>
    static bool isPrime(InputType inputNumber)
    {
        // Handle 2 by hand so we can skip every even numbers
        if ((inputNumber % 2) == 0)
        {
            return false;
        }

        InputType lowNumber = 3;

        InputType inputSquared = static_cast<InputType>(std::ceil(std::sqrt(inputNumber)));

        // Stop at sqrt since any higher number won't devide it
        while (lowNumber <= inputSquared)
        {
            if ((inputNumber % lowNumber) == 0)
            {
                return false;
            }
            lowNumber += 2;
        }

        return true;
    }
};
} // namespace libs
} // namespace my

#endif /* !_MATH_UTILS_H_ */