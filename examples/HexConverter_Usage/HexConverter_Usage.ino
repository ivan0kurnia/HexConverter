#include <HexConverter.h>

// Turns the builtin LED on and halts the microcontroller if the assertion results false
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
    Serial.begin(115200);

    Serial.print("-- HexConverter Function Library --");
    Serial.println();

    Serial.println();

    // Supports hex literal detection in the string
    const unsigned int integer1 = HexConverter::toInt("0xFF");
    Serial.print("integer1: ");
    Serial.print(integer1);
    Serial.println();
    myAssert(integer1 == 255 && integer1 == 0xFF);

    // No literal is also fine
    const unsigned int integer2 = HexConverter::toInt("FF");
    Serial.print("integer2: ");
    Serial.print(integer2);
    Serial.println();
    myAssert(integer2 == 255 && integer2 == 0xFF);

    // Also supports lowercase
    const unsigned int integer3 = HexConverter::toInt("ff");
    Serial.print("integer3: ");
    Serial.print(integer3);
    Serial.println();
    myAssert(integer3 == 255 && integer3 == 0xFF);

    // Supports up to eight hexadecimal characters (32-bit unsigned int), implementation dependent
    const unsigned int integer4 = HexConverter::toInt("0xDEADBEEF");
    Serial.print("integer4: ");
    Serial.print(integer4);
    Serial.println();
    myAssert(integer4 == 3735928559 && integer4 == 0xDEADBEEF);

    // Returns zero when the hexadecimal string length is more than HexConverter::MAXIMUM_STRING_LENGTH
    const unsigned int integer5 = HexConverter::toInt("0xADEADBEEF");
    Serial.print("integer5: ");
    Serial.print(integer5);
    Serial.println();
    myAssert(integer5 == 0);

    // Returns zero when the string is not a hexadecimal string
    const unsigned int integer6 = HexConverter::toInt("0xLOLOLOL");
    Serial.print("integer6: ");
    Serial.print(integer6);
    Serial.println();
    myAssert(integer6 == 0);

    // Ignores meaningless zeroes
    const unsigned int integer7 = HexConverter::toInt("0x0000000000DEADBEEF");
    Serial.print("integer7: ");
    Serial.print(integer7);
    Serial.println();
    myAssert(integer7 == 3735928559 && integer7 == 0xDEADBEEF);

    // Casting is also supported
    const unsigned int integer8 = HexConverter::toInt<unsigned char>("0xAA");
    Serial.print("integer8: ");
    Serial.print(integer8);
    Serial.println();
    myAssert(integer8 == 170 && integer8 == 0xAA);

    Serial.println();

    // Converts from integer to string too
    const String string1 = HexConverter::toString(3735928559);
    Serial.print("string1: ");
    Serial.print(string1);
    Serial.println();
    myAssert(string1 == "DEADBEEF");

    // Adds zeroes to satisfy the specified minimum length (4)
    const String string2 = HexConverter::toString(170, 4);
    Serial.print("string2: ");
    Serial.print(string2);
    Serial.println();
    myAssert(string2 == "00AA");

    // Returns full-valued hex string if the integer value exceeds the specified minimum length (4)
    const String string3 = HexConverter::toString(699050, 4);
    Serial.print("string3: ");
    Serial.print(string3);
    Serial.println();
    myAssert(string3 == "AAAAA");

    // There's also a function that returns hex string with its literal
    const String string4 = HexConverter::toStringWithLiteral(3735928559);
    Serial.print("string4: ");
    Serial.print(string4);
    Serial.println();
    myAssert(string4 == "0xDEADBEEF");

    // The function also supports minimum length specifics (4)
    const String string5 = HexConverter::toStringWithLiteral(170, 4);
    Serial.print("string5: ");
    Serial.print(string5);
    Serial.println();
    myAssert(string5 == "0x00AA");

    // Lastly, remember that values without double quotation marks are never strings
    const String string6 = HexConverter::toString(0xDEADBEEF);
    Serial.print("string6: ");
    Serial.print(string6);
    Serial.println();
    myAssert(string6 == "DEADBEEF");
}

void loop()
{
}