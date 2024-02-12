
#include "unity.h"

void test_TheFirst(void)
{
    //TEST_IGNORE_MESSAGE("Implement Me");
    //TEST_ASSERT(1 == 2);
    //TEST_ASSERT_MESSAGE(1 == 2, "2 did not equal 2");
    TEST_ASSERT_EQUAL(1,2);
}

void test_TheSecond(void){
    TEST_ASSERT_EQUAL(2,3);
}

void test_TheThird(void){
    TEST_ASSERT_EQUAL_FLOAT(1.1, 1.2);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_TheFirst);
    RUN_TEST(test_TheSecond);
    RUN_TEST(test_TheThird);
    return UNITY_END();
}

