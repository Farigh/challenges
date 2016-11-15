#ifndef _BIG_INT_H_
# define _BIG_INT_H_

# include <algorithm>
# include <cmath>
# include <cstdint>

namespace my {
namespace libs {

template<typename InnerType, int MaxSubDigits = 10, int MaxInnerListSize = 5>
class BigInt
{
public:
    using InnerDataType = InnerType[MaxInnerListSize];

    BigInt() = default;
    ~BigInt() = default;

    BigInt(InnerType n)
    {
        add(n);
    }

    BigInt(const InnerDataType& array)
    {
        std::copy(std::begin(array), std::end(array), std::begin(Data));
    }

    // Don't support different BigInt types right now
    void add(const BigInt<InnerType, MaxSubDigits, MaxInnerListSize>& number)
    {
        for (std::uint8_t i = (MaxInnerListSize - 1); ; --i)
        {
            Data[i] += number.Data[i];

            if (i == 0)
            {
                break;
            }
            else
            {
                const InnerType overflow = (Data[i] / _nextArrayMask);
                // Transfer the overflow to higher index
                if (overflow > 0)
                {
                    Data[i - 1] += overflow;
                    Data[i] %= _nextArrayMask;
                }
            }
        }
    }

    InnerType getFirstDigits(const std::uint64_t digitCount)
    {
        const std::uint64_t expectedDigitMask = static_cast<std::uint64_t>(std::pow(digitCount, 10));
        std::uint64_t result = Data[0];

        // Handle resultDigit > digitCount
        while (result >= expectedDigitMask)
        {
            result /= 10;
        }

        // Handle resultDigit < digitCount
        std::uint64_t restMask = (_nextArrayMask / 10);
        while (result < (expectedDigitMask / 10))
        {
            result *= 10;
            result += Data[1] / restMask;
            Data[1] %= restMask;
            restMask /= 10;
        }

        return result;
    }

    InnerDataType Data = { 0 };

private:
    // Mask to add 1 to the upper array
    static constexpr std::uint64_t _nextArrayMask = static_cast<std::uint64_t>(std::pow(MaxSubDigits, MaxSubDigits));
};

} // namespace libs
} // namespace my

#endif /* !_BIG_INT_H_ */