#include <HexConverter.h>

// Turns the builtin LED on and halts the microcontroller if the assertion result is false
void myAssert(bool toAssert)
{
    if (!toAssert)
    {
        pinMode(LED_BUILTIN, OUTPUT);
        digitalWrite(LED_BUILTIN, HIGH);

        while (true)
            delay(0);
    }
}

void setup()
{
    // Supports hex literal detection in the string
    const unsigned int integer1 = HexConverter::toUInt("0xFF");
    myAssert(integer1 == 255 && integer1 == 0xFF);

    // No literal is also fine
    const unsigned int integer2 = HexConverter::toUInt("FF");
    myAssert(integer2 == 255 && integer2 == 0xFF);

    // Also supports lowercase
    const unsigned int integer3 = HexConverter::toUInt("ff");
    myAssert(integer3 == 255 && integer3 == 0xFF);

    // Supports up to eight hexadecimal characters (32-bit unsigned int), implementation dependent
    const unsigned int integer4 = HexConverter::toUInt("0xDEADBEEF");
    myAssert(integer4 == 3735928559 && integer4 == 0xDEADBEEF);

    // Returns zero when the hexadecimal string length is more than HexConverter::MAXIMUM_STRING_LENGTH
    const unsigned int integer5 = HexConverter::toUInt("0xADEADBEEF");
    myAssert(integer5 == 0);

    // Returns zero when the string is not a hexadecimal string
    const unsigned int integer6 = HexConverter::toUInt("0xLOLOLOL");
    myAssert(integer6 == 0);

    // Ignores meaningless zeroes
    const unsigned int integer7 = HexConverter::toUInt("0x0000000000DEADBEEF");
    myAssert(integer7 == 3735928559 && integer7 == 0xDEADBEEF);

    // There are functions that return unsigned integers in the form of short and char too
    const unsigned int integer8 = HexConverter::toUChar("0xAA");
    myAssert(integer8 == 170 && integer8 == 0xAA);

    // Converts from integer to string too
    const String string1 = HexConverter::toString(3735928559);
    myAssert(string1 == "DEADBEEF");

    // Adds zeroes to satisfy the specified minimum length (4)
    const String string2 = HexConverter::toString(170, 4);
    myAssert(string2 == "00AA");

    // Returns full-valued hex string if the integer value exceeds the specified minimum length (4)
    const String string3 = HexConverter::toString(699050, 4);
    myAssert(string3 == "AAAAA");

    // There's also a function that returns hex string with its literal
    const String string4 = HexConverter::toStringWithLiteral(3735928559);
    myAssert(string4 == "0xDEADBEEF");

    // The function also supports minimum length specifics (4)
    const String string5 = HexConverter::toStringWithLiteral(170, 4);
    myAssert(string5 == "0x00AA");

    // Lastly, remember that values without double quotation marks are never strings
    const String string6 = HexConverter::toString(0xDEADBEEF);
    myAssert(string6 == "DEADBEEF");
}

void loop()
{
}
