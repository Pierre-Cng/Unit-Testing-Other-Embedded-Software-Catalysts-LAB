#include "unity.h"
#include "GPIO.h"
#include "MK20DX256.h"

void test_SetPinAsOutput_should_ConfigurePinDirection(void)
{
    PORTC.PDDR=0;

    GPIO_SetPinAsOutput(0);
    TEST_ASSERT_EQUAL_HEX32(BIT_TO_MASK(0), PORTC.PDDR);

    GPIO_SetPinAsOutput(22);
    TEST_ASSERT_EQUAL_HEX32(BIT_TO_MASK(0)|BIT_TO_MASK(22), PORTC.PDDR);

    GPIO_SetPinAsOutput(31);
    TEST_ASSERT_EQUAL_HEX32(BIT_TO_MASK(0)|BIT_TO_MASK(22)|BIT_TO_MASK(31), PORTC.PDDR);

}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_SetPinAsOutput_should_ConfigurePinDirection);
    return UNITY_END();
}
