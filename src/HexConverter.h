#ifndef HEX_CONVERTER_h
#define HEX_CONVERTER_h

#include <Arduino.h>

// Member functions of this class doesn't deal with 64-bit long long long data type
class HexConverter
{
public:
    HexConverter() = delete;

    static const unsigned int MAXIMUM_STRING_LENGTH = 2U * sizeof(unsigned int);

    // Use the function template with fundamental data types only
    template <typename T>
    static const T toInt(String hexString);
    static const unsigned int toInt(String hexString) { return toInt<unsigned int>(hexString); }

    static const String toString(const unsigned int integer, unsigned int minimumLength = 1U);
    static const String toStringWithLiteral(const unsigned int integer, unsigned int minimumLength = 1U) { return "0x" + toString(integer, minimumLength); }
};

#endif