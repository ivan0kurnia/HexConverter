#ifndef HEX_CONVERTER_h
#define HEX_CONVERTER_h

#include <Arduino.h>

// Member functions of this class doesn't deal with 64-bit long long long data type
class HexConverter
{
public:
    HexConverter() = delete;

    static const unsigned int MAXIMUM_STRING_LENGTH = 2U * sizeof(uint32_t);

    static const uint32_t toUInt(String hexString);
    static const uint16_t toUShort(String hexString) { return static_cast<uint16_t>(toUInt(hexString)); }
    static const uint8_t toUChar(String hexString) { return static_cast<uint8_t>(toUInt(hexString)); }

    static const String toString(const unsigned int integer, unsigned int minimumLength = 1U);
    static const String toStringWithLiteral(const unsigned int integer, unsigned int minimumLength = 1U) { return "0x" + toString(integer, minimumLength); }
};

#endif