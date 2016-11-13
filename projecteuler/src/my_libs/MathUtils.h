#ifndef _MATH_UTILS_H_
# define _MATH_UTILS_H_

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
    static bool isPrime(InputType inputNumber)
    {
        std::list<InputType> result;

        InputType lowNumber = 1;

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
};
} // namespace libs
} // namespace my

#endif /* !_MATH_UTILS_H_ */