#ifndef _BIG_INT_H_
# define _BIG_INT_H_

# include <algorithm>
# include <cmath>
# include <cstdint>
# include <iomanip>
# include <sstream>

namespace my {
namespace libs {

template<typename InnerType, std::uint32_t MaxInnerListSize = 5, std::uint32_t MaxSubDigits = 10>
class BigInt
{
public:
    using InnerDataType = InnerType[MaxInnerListSize];

    BigInt() = default;
    ~BigInt() = default;

    BigInt(InnerType n)
    {
        InnerDataType toAdd = { 0 };
        toAdd[MaxInnerListSize - 1] = n;
        add(toAdd);
    }

    BigInt(const InnerDataType& array)
    {
        std::copy(std::begin(array), std::end(array), std::begin(Data));
    }

    // Don't support different BigInt types right now
    void add(const BigInt<InnerType, MaxInnerListSize, MaxSubDigits>& number)
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

    std::string toString() const
    {
        std::ostringstream formater;

        bool isFirst = true;
        for (std::uint8_t i = 0; i < MaxInnerListSize; ++i)
        {
            // Avoid leading 0s
            if (isFirst && (Data[i] == 0))
            {
                continue;
            }

            if (isFirst)
            {
                isFirst = false;
            }
            else
            {
                // Add padding
                formater << std::setfill('0') << std::setw(MaxSubDigits);
            }

            formater << Data[i];
        }

        return formater.str();
    }

    std::uint32_t getMaxInnerListSize()
    {
        return MaxInnerListSize;
    }

    InnerDataType Data = { 0 };

private:
    // Mask to add 1 to the upper array
    static constexpr std::uint64_t _nextArrayMask = static_cast<std::uint64_t>(std::pow(10, MaxSubDigits));
};

} // namespace libs
} // namespace my

#endif /* !_BIG_INT_H_ */